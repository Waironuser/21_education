#include "s21_sscanf.h"

int s21_sscanf(const char *str, const char *format, ...) {
  st_format_item format_item = {0};
  va_list args;
  va_start(args, format);
  int count = 0;
  int return_value = 0;
  const char *temp_str = str;
  while (*temp_str) {
    if (!is_space(*temp_str)) break;
    temp_str++;
  }
  if (*temp_str == '\0') {
    return_value = EOF;
  } else {
    while (*format && *str) {
      if (*format != '%') {
        if (*format != *str) break;
        format++;
        str++;
        continue;
      } else {
        format++;
        format_item.suppress_assignment = 0;
        if (*format == '*') {
          format_item.suppress_assignment = 1;
          format++;
        }
        format = parse_w(&format_item, format);
        format = parse_len(&format_item, format);
        format = parse_spec(&format_item, format);
        count += specifier_selector(&str, &format_item, &args);
      }
    }
    return_value = count;
  }
  va_end(args);
  return return_value;
}

const char *parse_w(st_format_item *format_item, const char *format) {
  format_item->width = 0;
  while (*format >= '0' && *format <= '9') {
    format_item->width = format_item->width * 10 + (*format - '0');
    format++;
  }
  return format;
}

const char *parse_len(st_format_item *format_item, const char *format) {
  if (*format == 'l' || *format == 'h') {
    format_item->len = *format;
    format++;
  } else {
    format_item->len = '\0';
  }
  return format;
}

const char *parse_spec(st_format_item *format_item, const char *format) {
  if (s21_strchr("dscifeEgGouxXp", *format)) {
    format_item->specifier = *format;
    format++;
  }
  return format;
}

const char *preprocess_string(const char *str, int width) {
  static char buffer[1024];
  const char *start = str;
  char *buf_ptr = buffer;
  int count = 0;
  while (*start && !is_space(*start) && (width == 0 || count < width)) {
    *buf_ptr++ = *start++;
    count++;
  }
  *buf_ptr = '\0';
  return buffer;
}

int specifier_selector(const char **str, st_format_item *format_item,
                       va_list *args) {
  int count = 0;
  const char *processed_str = preprocess_string(*str, format_item->width);
  switch (format_item->specifier) {
    case 'd':
      count = d_specifier(processed_str, format_item, args);
      break;
    case 'c':
      count = c_specifier(processed_str, format_item, args);
      break;
    case 's':
      count = s_specifier(processed_str, format_item, args);
      break;
    case 'f':
      count = f_specifier(processed_str, format_item, args);
      break;
    case 'i':
      count = i_specifier(processed_str, format_item, args);
      break;
    case 'e':
    case 'E':
    case 'g':
    case 'G':
      count = eEgG_specifier(processed_str, format_item, args);
      break;
    case 'o':
      count = o_specifier(processed_str, format_item, args);
      break;
    case 'u':
      count = u_specifier(processed_str, format_item, args);
      break;
    case 'x':
    case 'X':
      count = xX_specifier(processed_str, format_item, args);
      break;
    case 'p':
      count = p_specifier(processed_str, format_item, args);
      break;
    case 'n':
      count = n_specifier(processed_str, format_item, args);
      break;
  }
  *str += s21_strlen(processed_str);
  return count;
}

int d_specifier(const char *str, st_format_item *format_item, va_list *args) {
  int flag = 1;
  if (format_item->suppress_assignment) flag = 0;
  if (flag) {
    if (format_item->len == 'l') {
      long *d = va_arg(*args, long *);
      *d = str_to_int(str);
    } else if (format_item->len == 'h') {
      short *d = va_arg(*args, short *);
      *d = (short)str_to_int(str);
    } else {
      int *d = va_arg(*args, int *);
      *d = str_to_int(str);
    }
  }
  return flag;
}

int c_specifier(const char *str, st_format_item *format_item, va_list *args) {
  int flag = 1;
  if (format_item->suppress_assignment) flag = 0;
  if (flag) {
    if (format_item->len == 'l') {
      wchar_t *wc = va_arg(*args, wchar_t *);
      mbtowc(wc, str, MB_CUR_MAX);
    } else {
      char *c = va_arg(*args, char *);
      *c = *str;
    }
  }
  return flag;
}

int s_specifier(const char *str, st_format_item *format_item, va_list *args) {
  int flag = 1;
  if (format_item->suppress_assignment) flag = 0;
  if (flag) {
    if (format_item->len == 'l') {
      wchar_t *ws = va_arg(*args, wchar_t *);
      while (*str) {
        int len = mbtowc(ws, str, MB_CUR_MAX);
        if (len < 0) break;
        ws++;
        str += len;
      }
      *ws = L'\0';
    } else {
      char *s = va_arg(*args, char *);
      while (*str) {
        *s++ = *str++;
      }
      *s = '\0';
    }
  }
  return flag;
}

int f_specifier(const char *str, st_format_item *format_item, va_list *args) {
  int flag = 1;
  if (format_item->suppress_assignment) flag = 0;
  if (flag) {
    if (format_item->len == 'L') {
      long double *f = va_arg(*args, long double *);
      *f = str_to_long_double(str);
    } else if (format_item->len == 'l') {
      double *f = va_arg(*args, double *);
      *f = str_to_double(str);
    } else {
      float *f = va_arg(*args, float *);
      *f = str_to_float(str);
    }
  }
  return flag;
}

int i_specifier(const char *str, st_format_item *format_item, va_list *args) {
  int flag = 1;
  if (format_item->suppress_assignment) flag = 0;
  if (flag) {
    int value;
    if (str[0] == '0') {
      if (str[1] == 'x' || str[1] == 'X') {
        value = (int)str_to_hex(str + 2);
      } else {
        value = (int)str_to_octal(str);
      }
    } else if (str[0] >= '0' && str[0] <= '9') {
      if (s21_strchr(str, 'a') || s21_strchr(str, 'b') ||
          s21_strchr(str, 'c') || s21_strchr(str, 'd') ||
          s21_strchr(str, 'e') || s21_strchr(str, 'f') ||
          s21_strchr(str, 'A') || s21_strchr(str, 'B') ||
          s21_strchr(str, 'C') || s21_strchr(str, 'D') ||
          s21_strchr(str, 'E') || s21_strchr(str, 'F')) {
        value = (int)str_to_hex(str);
      } else {
        value = str_to_int(str);
      }
    } else {
      value = str_to_int(str);
    }
    if (format_item->len == 'h') {
      short *i = va_arg(*args, short *);
      *i = (short)value;
    } else {
      int *i = va_arg(*args, int *);
      *i = value;
    }
  }
  return flag;
}

int eEgG_specifier(const char *str, st_format_item *format_item,
                   va_list *args) {
  int flag = 1;
  if (format_item->suppress_assignment) flag = 0;
  if (flag) {
    if (format_item->len == 'L') {
      long double *f = va_arg(*args, long double *);
      *f = str_to_long_double(str);
    } else if (format_item->len == 'l') {
      double *f = va_arg(*args, double *);
      *f = str_to_double(str);
    } else {
      float *f = va_arg(*args, float *);
      *f = str_to_float(str);
    }
  }
  return flag;
}

int o_specifier(const char *str, st_format_item *format_item, va_list *args) {
  int flag = 1;
  if (format_item->suppress_assignment) flag = 0;
  if (flag) {
    if (format_item->len == 'h') {
      unsigned short *o = va_arg(*args, unsigned short *);
      *o = (unsigned short)str_to_octal(str);
    } else if (format_item->len == 'l') {
      unsigned long *o = va_arg(*args, unsigned long *);
      *o = str_to_octal(str);
    } else {
      unsigned int *o = va_arg(*args, unsigned int *);
      *o = str_to_octal(str);
    }
  }
  return flag;
}

int u_specifier(const char *str, st_format_item *format_item, va_list *args) {
  int flag = 1;
  if (format_item->suppress_assignment) flag = 0;
  if (flag) {
    if (format_item->len == 'h') {
      unsigned short *u = va_arg(*args, unsigned short *);
      *u = (unsigned short)str_to_unsigned_int(str);
    } else if (format_item->len == 'l') {
      unsigned long *u = va_arg(*args, unsigned long *);
      *u = str_to_unsigned_int(str);
    } else {
      unsigned int *u = va_arg(*args, unsigned int *);
      *u = str_to_unsigned_int(str);
    }
  }
  return flag;
}

int xX_specifier(const char *str, st_format_item *format_item, va_list *args) {
  int flag = 1;
  if (format_item->suppress_assignment) flag = 0;
  if (flag) {
    if (format_item->len == 'h') {
      unsigned short *x = va_arg(*args, unsigned short *);
      *x = (unsigned short)str_to_hex(str);
    } else if (format_item->len == 'l') {
      unsigned long *x = va_arg(*args, unsigned long *);
      *x = str_to_hex(str);
    } else {
      unsigned int *x = va_arg(*args, unsigned int *);
      *x = str_to_hex(str);
    }
  }
  return flag;
}

int p_specifier(const char *str, st_format_item *format_item, va_list *args) {
  int flag = 1;
  if (format_item->suppress_assignment) flag = 0;
  if (flag) {
    void **p = va_arg(*args, void **);
    *p = (void *)(uintptr_t)str_to_hex(str);
  }
  return flag;
}

int n_specifier(const char *str, st_format_item *format_item, va_list *args) {
  int flag = 1;
  if (format_item->suppress_assignment) flag = 0;
  if (flag) {
    int *n = va_arg(*args, int *);
    *n = (int)(str - str);
  }
  return flag;
}

int is_space(char c) {
  return (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' ||
          c == '\r');
}

int is_digit(char c) { return c >= '0' && c <= '9'; }

int str_to_int(const char *str) {
  int result = 0;
  int sign = 1;
  if (*str == '-') {
    sign = -1;
    str++;
  }
  while (*str >= '0' && *str <= '9') {
    result = result * 10 + (*str - '0');
    str++;
  }
  return result * sign;
}

float str_to_float(const char *str) {
  float num = 0.0;
  float factor = 1.0;
  int sign = 1;
  if (*str == '-') {
    sign = -1;
    str++;
  }
  while (is_digit(*str)) {
    num = num * 10.0 + (*str - '0');
    str++;
  }
  if (*str == '.') {
    str++;
    while (is_digit(*str)) {
      factor /= 10.0;
      num += (*str - '0') * factor;
      str++;
    }
  }
  if (*str == 'e' || *str == 'E') {
    str++;
    int exp_sign = 1;
    if (*str == '-') {
      exp_sign = -1;
      str++;
    } else if (*str == '+') {
      str++;
    }
    int exponent = str_to_int(str);
    num *= pow(10, exp_sign * exponent);
  }
  return sign * num;
}

double str_to_double(const char *str) { return (double)str_to_float(str); }

long double str_to_long_double(const char *str) {
  return (long double)str_to_float(str);
}

unsigned int str_to_unsigned_int(const char *str) {
  unsigned int result = 0;
  while (*str >= '0' && *str <= '9') {
    result = result * 10 + (*str - '0');
    str++;
  }
  return result;
}

unsigned long str_to_octal(const char *str) {
  unsigned long result = 0;
  while (*str >= '0' && *str <= '7') {
    result = result * 8 + (*str - '0');
    str++;
  }
  return result;
}

unsigned long str_to_hex(const char *str) {
  unsigned long result = 0;
  if (*str == '0' && *(str + 1) == 'x') {
    str += 2;
  }
  while ((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'f') ||
         (*str >= 'A' && *str <= 'F')) {
    result = result * 16;
    if (*str >= '0' && *str <= '9') {
      result += *str - '0';
    } else if (*str >= 'a' && *str <= 'f') {
      result += *str - 'a' + 10;
    } else if (*str >= 'A' && *str <= 'F') {
      result += *str - 'A' + 10;
    }
    str++;
  }
  return result;
}