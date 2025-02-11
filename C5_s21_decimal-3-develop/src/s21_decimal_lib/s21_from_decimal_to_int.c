#include "../sobektof_lib/sobektof.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error_ind = 0;

  s21_decimal truncated_decimal = {{0, 0, 0, 0}};
  if (!dst) {
    error_ind = 1;
  } else if (!s21_is_correct_decimal(src)) {
    error_ind = 1;
  } else {
    s21_truncate(src, &truncated_decimal);
    if (truncated_decimal.bits[MIDDLE] != 0 ||
        truncated_decimal.bits[HIGH] != 0) {
      error_ind = 1;
    }
  }

  if (error_ind == 1) {
    *dst = 0;
  } else {
    if (s21_decimal_get_info(truncated_decimal, SIGN) == 1 &&
        *dst != -2147483648) {
      *dst = truncated_decimal.bits[LOW] * -1;
    } else {
      *dst = truncated_decimal.bits[LOW];
    }
  }
  return error_ind;
}