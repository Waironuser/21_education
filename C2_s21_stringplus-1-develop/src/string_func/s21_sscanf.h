#ifndef S21_SSCANF_H
#define S21_SSCANF_H

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "../s21_string.h"

typedef struct {
  int width;
  char len;
  char specifier;
  int suppress_assignment;
} st_format_item;

int s21_sscanf(const char *str, const char *format, ...);
const char *parse_w(st_format_item *format_item, const char *format);
const char *parse_len(st_format_item *format_item, const char *format);
const char *parse_spec(st_format_item *format_item, const char *format);
const char *preprocess_string(const char *str, int width);
int specifier_selector(const char **str, st_format_item *format_item,
                       va_list *args);
int d_specifier(const char *str, st_format_item *format_item, va_list *args);
int c_specifier(const char *str, st_format_item *format_item, va_list *args);
int s_specifier(const char *str, st_format_item *format_item, va_list *args);
int f_specifier(const char *str, st_format_item *format_item, va_list *args);
int i_specifier(const char *str, st_format_item *format_item, va_list *args);
int eEgG_specifier(const char *str, st_format_item *format_item, va_list *args);
int o_specifier(const char *str, st_format_item *format_item, va_list *args);
int u_specifier(const char *str, st_format_item *format_item, va_list *args);
int xX_specifier(const char *str, st_format_item *format_item, va_list *args);
int p_specifier(const char *str, st_format_item *format_item, va_list *args);
int n_specifier(const char *str, st_format_item *format_item, va_list *args);
int is_digit(char c);
int is_space(char c);
int str_to_int(const char *str);
float str_to_float(const char *str);
double str_to_double(const char *str);
long double str_to_long_double(const char *str);
unsigned int str_to_unsigned_int(const char *str);
unsigned long str_to_octal(const char *str);
unsigned long str_to_hex(const char *str);

#endif  // S21_SSCANF_H