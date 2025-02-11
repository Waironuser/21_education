#ifndef SOBEKTOF_H
#define SOBEKTOF_H

#include "./s21_decimal_get_set_info_bits.h"
#include "./s21_decimal_types_enums.h"

void s21_parse_float(int *sign, int *mantissa, int *exp, char *scientific_str);
int s21_div_no_remainder(s21_decimal dividend, s21_decimal divisor,
                         s21_decimal *quotient, s21_decimal *remainder);
s21_decimal s21_decimal_shift_left(int upper, int middle, int lower, int count);
s21_decimal s21_decimal_shift_right(int upper, int middle, int lower,
                                    int count);
void s21_process_remainder(s21_decimal remainder, s21_decimal divisor,
                           s21_decimal *result, int nums_already);

#endif