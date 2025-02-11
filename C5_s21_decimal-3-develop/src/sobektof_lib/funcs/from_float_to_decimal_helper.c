#include "../sobektof.h"

void s21_parse_float(int *sign, int *mantissa, int *exp, char *scientific_str) {
  int index = 1;
  if (scientific_str[index] == '-') {
    *sign = 1;
    index++;
  } else {
    *sign = 0;
  }

  int mantissa_minus = 0;
  *mantissa = 0;
  while (scientific_str[index] != 'E') {
    if (scientific_str[index] != '.') {
      *mantissa = *mantissa * 10;
      *mantissa = *mantissa + scientific_str[index] - 48;
      mantissa_minus++;
    }
    index++;
  }
  mantissa_minus--;
  index++;
  int exp_mult;
  if (scientific_str[index] == '+') {
    exp_mult = -1;
  } else {
    exp_mult = 1;
  }
  index++;

  while (scientific_str[index] != '\0') {
    *exp = *exp * 10;
    *exp = *exp + scientific_str[index] - 48;
    index++;
  }

  *exp = *exp * exp_mult + mantissa_minus;
  while (*exp > 28) {
    *mantissa = *mantissa / 10;
    *exp = *exp - 1;
  }
  while (*exp > 0 && *mantissa % 10 == 0) {
    *exp = *exp - 1;
    *mantissa = *mantissa / 10;
  }
}
