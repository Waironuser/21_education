#include "../other.h"

void s21_add_helper(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result, int sign, int *err_flag) {
  s21_decimal correct_num1 = {{0, 0, 0, 0}};
  s21_decimal correct_num2 = {{0, 0, 0, 0}};
  s21_normalize(value_1, value_2, &correct_num1, &correct_num2);
  s21_decimal_set_sign(result, sign);
  s21_decimal_set_power(result, s21_decimal_get_power(correct_num1));
  int remainder = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 32; j++) {
      int sum = (correct_num1.bits[i] >> j & 1) +
                (correct_num2.bits[i] >> j & 1) + remainder;
      if (sum == 3) {
        result->bits[i] |= (1 << j);  // = 1
        remainder = 1;
      } else if (sum == 2) {
        result->bits[i] &= ~(1 << j);  // = 0
        remainder = 1;
      } else if (sum == 1) {
        result->bits[i] |= (1 << j);
        remainder = 0;
      } else if (sum == 0) {
        result->bits[i] &= ~(1 << j);
        remainder = 0;
      }
    }
  }
  if (remainder) {
    *err_flag = 1;
    for (int i = 0; i < 4; i++) result->bits[i] = 0;
  }
}

void s21_sub_helper(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result, int sign) {
  // первое число всегда больше второго по мантиссе
  s21_decimal correct_num1 = {{0, 0, 0, 0}};
  s21_decimal correct_num2 = {{0, 0, 0, 0}};
  s21_normalize(value_1, value_2, &correct_num1, &correct_num2);
  s21_decimal_set_sign(result, sign);
  s21_decimal_set_power(result, s21_decimal_get_power(correct_num1));
  int remainder = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 32; j++) {
      int num1 = (correct_num1.bits[i] >> j & 1);
      int num2 = (correct_num2.bits[i] >> j & 1);
      if (num1 == 1 && remainder) {
        num1 = 0;
        remainder = 0;
      }
      if (!remainder && num1 - num2 < 0) {
        remainder = 1;
        num1 = 2;
      } else if (remainder)
        num1++;
      if (num1 - num2 > 0) {
        result->bits[i] |= (1 << j);
      } else {
        result->bits[i] &= ~(1 << j);
      };
    }
  }
}

int s21_mantissa_compare(s21_decimal num1, s21_decimal num2) {
  int flag = 1, result = EQUAL;
  for (int i = 2; i >= 0 && flag; i--) {
    for (int j = 31; j >= 0 && flag; j--) {
      if (((num1.bits[i] >> j) & 1) == ((num2.bits[i] >> j) & 1)) {
        continue;
      } else if (((num1.bits[i] >> j) & 1) < ((num2.bits[i] >> j) & 1)) {
        flag = 0;
        result = LESS;
      } else if (((num1.bits[i] >> j) & 1) > ((num2.bits[i] >> j) & 1)) {
        flag = 0;
        result = MORE;
      }
    }
  }
  return result;
}

void s21_round_10(s21_decimal *num) {
  s21_decimal new_result = {{0, 0, 0, 0}};
  int power_remember = s21_decimal_get_power(*num);
  s21_decimal_set_power(num, 1);
  s21_round(*num, &new_result);
  s21_decimal_set_power(&new_result, power_remember - 1);
  *num = new_result;
}

void s21_normalize(s21_decimal num1, s21_decimal num2, s21_decimal *result1,
                   s21_decimal *result2) {
  *result1 = num1;
  *result2 = num2;
  if (s21_decimal_get_power(num1) == s21_decimal_get_power(num2)) return;

  if (s21_decimal_get_power(num1) > s21_decimal_get_power(num2)) {
    int diff = s21_decimal_get_power(num1) - s21_decimal_get_power(num2);
    s21_decimal_set_power(result2, 0);
    for (int i = 0; i < diff; i++) {
      s21_decimal new_result = {{0, 0, 0, 0}};
      if (s21_is_greater(*result2, (s21_decimal){{0x19999999, 0x99999999,
                                                  0x99999999, 0}}) ||
          s21_is_less(*result2, (s21_decimal){{0x19999999, 0x99999999,
                                               0x99999999, 0x80000000}}))
        s21_round_10(result1);
      else {
        s21_mul(*result2, (s21_decimal){{10, 0, 0, 0}}, &new_result);
        *result2 = new_result;
      }
    }
    s21_decimal_set_power(result2, s21_decimal_get_power(*result1));
  } else if (s21_decimal_get_power(num1) < s21_decimal_get_power(num2)) {
    int diff = s21_decimal_get_power(num2) - s21_decimal_get_power(num1);
    s21_decimal_set_power(result1, 0);
    for (int i = 0; i < diff; i++) {
      s21_decimal new_result = {{0, 0, 0, 0}};
      if (s21_is_greater(*result1, (s21_decimal){{0x19999999, 0x99999999,
                                                  0x99999999, 0}}) ||
          s21_is_less(*result1, (s21_decimal){{0x19999999, 0x99999999,
                                               0x99999999, 0x80000000}}))
        s21_round_10(result2);
      else {
        s21_mul(*result1, (s21_decimal){{10, 0, 0, 0}}, &new_result);
        *result1 = new_result;
      }
    }
    s21_decimal_set_power(result1, s21_decimal_get_power(*result2));
  }
  s21_decimal_set_sign(result1, s21_decimal_get_sign(num1));
  s21_decimal_set_sign(result2, s21_decimal_get_sign(num2));
}

// void print_binary(int num) {
//   for (int i = 31; i >= 0; i--) printf("%d", (num >> i) & 1);
//   printf("\n");
// }

// void print_decimal(s21_decimal num) {
//   for (int i = 3; i >= 0; i--) print_binary(num.bits[i]);
// }
