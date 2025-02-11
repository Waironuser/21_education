#include "../sobektof.h"

int s21_div_no_remainder(s21_decimal dividend, s21_decimal divisor,
                         s21_decimal* quotient, s21_decimal* remainder) {
  int err_flag = 0;
  s21_decimal temp = dividend;
  int prev_flag = 0;
  if (s21_is_greater(divisor, dividend)) prev_flag = 1;
  while (s21_is_greater_or_equal(temp, divisor) && prev_flag == 0 &&
         err_flag == 0) {
    int shift = 0;
    while (s21_is_less_or_equal(
               s21_decimal_shift_left(divisor.bits[LOW], divisor.bits[MIDDLE],
                                      divisor.bits[HIGH], shift),
               temp) &&
           s21_is_less_or_equal(
               s21_decimal_shift_left(divisor.bits[LOW], divisor.bits[MIDDLE],
                                      divisor.bits[HIGH], shift),
               (s21_decimal){{0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF, 0}})) {
      shift++;
    }
    shift--;
    s21_decimal addition = s21_decimal_shift_left(1, 0, 0, shift);
    s21_decimal new_quotient = {{0, 0, 0, 0}};
    err_flag = s21_add(addition, *quotient, &new_quotient);
    *quotient = new_quotient;
    s21_decimal new_temp = {{0, 0, 0, 0}};
    err_flag =
        s21_sub(temp,
                s21_decimal_shift_left(divisor.bits[LOW], divisor.bits[MIDDLE],
                                       divisor.bits[HIGH], shift),
                &new_temp);
    temp = new_temp;
  }
  *remainder = temp;
  return err_flag;
}

s21_decimal s21_decimal_shift_left(int lower, int middle, int upper,
                                   int shift_count) {
  if (shift_count > 96) shift_count = 96;

  if (shift_count == 0) {
    return (s21_decimal){{lower, middle, upper, 0}};
  }

  int full_shifts = shift_count / 32;
  int remaining_shifts = shift_count % 32;

  unsigned int new_lower = lower;
  unsigned int new_middle = middle;
  unsigned int new_upper = upper;

  if (full_shifts >= 1) {
    new_upper = middle;
    new_middle = lower;
    new_lower = 0;
  }
  if (full_shifts == 2) {
    new_upper = lower;
    new_middle = 0;
    new_lower = 0;
  }

  if (remaining_shifts > 0) {
    unsigned int carry_middle = new_middle >> (32 - remaining_shifts);
    unsigned int carry_lower = new_lower >> (32 - remaining_shifts);

    new_upper = (new_upper << remaining_shifts) | carry_middle;
    new_middle = (new_middle << remaining_shifts) | carry_lower;
    new_lower <<= remaining_shifts;
  }

  s21_decimal result = {{new_lower, new_middle, new_upper, 0}};
  return result;
}

s21_decimal s21_decimal_shift_right(int lower, int middle, int upper,
                                    int shift_count) {
  if (shift_count > 96) shift_count = 96;
  if (shift_count == 0) {
    return (s21_decimal){{lower, middle, upper, 0}};
  }
  int full_shifts = shift_count / 32;
  int remaining_shifts = shift_count % 32;
  unsigned int new_lower = lower;
  unsigned int new_middle = middle;
  unsigned int new_upper = upper;
  if (full_shifts >= 1) {
    new_lower = middle;
    new_middle = upper;
    new_upper = 0;
  }
  if (full_shifts == 2) {
    new_lower = upper;
    new_middle = 0;
    new_upper = 0;
  }
  if (remaining_shifts > 0) {
    unsigned int carry_middle = new_middle << (32 - remaining_shifts);
    unsigned int carry_upper = new_upper << (32 - remaining_shifts);
    new_lower = (new_lower >> remaining_shifts) | carry_middle;
    new_middle = (new_middle >> remaining_shifts) | carry_upper;
    new_upper >>= remaining_shifts;
  }
  s21_decimal result = {{new_lower, new_middle, new_upper, 0}};
  return result;
}

void s21_process_remainder(s21_decimal remainder, s21_decimal divisor,
                           s21_decimal* result, int nums_arleady) {
  int count = nums_arleady;
  s21_decimal multiplier = {{10, 0, 0, 0}};
  while (count < 29 && !s21_decimal_equals_zero(remainder)) {
    s21_decimal new_dividend = {{0, 0, 0, 0}};
    s21_decimal new_quotient = {{0, 0, 0, 0}};
    s21_decimal new_remainder = {{0, 0, 0, 0}};
    if (s21_is_greater_or_equal(
            remainder,
            (s21_decimal){{0x9999999A, 0x99999999, 0x19999999, 0}})) {
      s21_decimal new_divisor = {{0, 0, 0, 0}};
      s21_div_no_remainder(divisor, multiplier, &new_divisor, &new_remainder);
      new_remainder = (s21_decimal){{0, 0, 0, 0}};
      new_dividend = remainder;
      divisor = new_divisor;
    } else {
      s21_mul(remainder, multiplier, &new_dividend);
    }
    s21_div_no_remainder(new_dividend, divisor, &new_quotient, &new_remainder);
    s21_decimal new_result = {{0, 0, 0, 0}};
    s21_mul(*result, multiplier, &new_result);
    *result = new_result;
    s21_add(*result, new_quotient, &new_result);
    *result = new_result;
    remainder = new_remainder;
    count++;
  }
  s21_decimal_set_power(result, count - nums_arleady);
}
