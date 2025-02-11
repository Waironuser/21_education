#include "../cherlyma_lib/cherlyma.h"

int s21_add(s21_decimal num, s21_decimal num2, s21_decimal *res) {
  int result = 0;
  int sign = get_sign(num);
  int sign2 = get_sign(num2);
  dec_to_null(res);
  if (correct(num) && correct(num2)) {
    scale_equalize(&num, &num2);
    set_scale(res, get_scale(num));
    result = 0;
    // }
    result = add_and_sign(num, num2, res, sign, sign2);
    if (first_unzero_bit(*res) && get_scale(*res)) {
      round_float(res);
    }
    if (first_unzero_bit(*res) && !get_sign(*res)) {
      result = 1;
    } else if (first_unzero_bit(*res) && get_sign(*res)) {
      result = 2;
    }
  } else
    result = 4;
  if (result) {
    dec_to_null(res);
    set_sign(res, 0);
  }
  return result;
}