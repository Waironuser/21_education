#include "../cherlyma_lib/cherlyma.h"

int s21_is_less_or_equal(s21_decimal d1, s21_decimal d2) {  // <=
  int res = (comparison(d1, d2) == 2) || (comparison(d1, d2) == 0);
  return res ? 1 : 0;
}