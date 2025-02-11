#include "../sobektof_lib/sobektof.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int error_ind = 0;
  int value = src;
  if (!dst) {
    error_ind = 1;
  } else {
    *dst = (s21_decimal){{0, 0, 0, 0}};
    if (src < 0 && src != -2147483648) {
      s21_decimal_set_sign(dst, 1);
      value = -1 * value;
    }
    dst->bits[LOW] = value;
  }
  return error_ind;
}
