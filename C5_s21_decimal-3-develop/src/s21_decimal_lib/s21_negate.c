#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = value;
  int sign_position = 31;
  int mask = 1 << sign_position;
  result->bits[3] = result->bits[3] ^ mask;
  return 0;
}