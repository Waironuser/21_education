#ifndef OTHER_H
#define OTHER_H

#include <stdint.h>

#include "../s21_decimal.h"
#include "../sobektof_lib/sobektof.h"

#define FALSE 0
#define TRUE 1
#define NOT_EQUAL 0
#define EQUAL 1
#define LESS -1
#define MORE 2

void s21_add_helper(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result, int sign, int *err_flag);
void s21_sub_helper(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result, int sign);
void s21_round_10(s21_decimal *num);

// нормализует мантиссы числа, уравнивая их степени и не изменяя знаки
void s21_normalize(s21_decimal num1, s21_decimal num2, s21_decimal *result1,
                   s21_decimal *result2);
int s21_mantissa_compare(s21_decimal num1, s21_decimal num2);

// void print_binary(int num);
// void print_decimal(s21_decimal num);

#endif