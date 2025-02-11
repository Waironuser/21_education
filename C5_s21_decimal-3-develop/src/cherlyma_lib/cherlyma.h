#ifndef CHERLYMA_H
#define CHERLYMA_H

#include "../s21_decimal.h"
#include "../sobektof_lib/sobektof.h"
#include "../lavadaja_lib/lavadaja.h"

#define MAX_FLOAT_TO_CONVERT 79228157791897854723898736640.0f
#define MIN_FLOAT_TO_CONVERT \
  0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f

typedef struct big_decimal {
  int bits[8];
} big_decimal;

void dec_to_null(s21_decimal *num);
int correct(s21_decimal num);
int s21_zero(s21_decimal num);
int multiplication(s21_decimal num, s21_decimal num2, s21_decimal *res);
void set_bit(s21_decimal *num, int index, int bit);
int get_bit(s21_decimal num, int x);
int get_scale(s21_decimal num);
void decimal_to_bigdecimal(s21_decimal value_1, big_decimal *value_2);
int left_for_big(big_decimal *num, int shift);
int plus_bigdec(big_decimal num, big_decimal num2, big_decimal *res);
int overflow(big_decimal value);
void round_float_big(big_decimal *num);
void bigdecimal_to_decimal(s21_decimal *value_1, big_decimal value_2);
void round_float(s21_decimal *num);
void set_bit_big(big_decimal *num, int index, int bit);
int get_bit_big(big_decimal num, int x);
void big_div_to_10(big_decimal *num, unsigned *rest);
void s21_div_to_10(s21_decimal *num, unsigned *rest);
int plus(s21_decimal num, s21_decimal num2, s21_decimal *res);
void set_scale(s21_decimal *num, int scl);
void set_sign(s21_decimal *num, int sig);
int get_sign(s21_decimal num);

int scale_equalize(s21_decimal *num, s21_decimal *num2);
int add_and_sign(s21_decimal num, s21_decimal num2, s21_decimal *res, int sign,
                 int sign2);
int first_unzero_bit(s21_decimal num);
void increase(s21_decimal *big, s21_decimal *small, s21_decimal *tmp,
              int *scaleS);
void minus(s21_decimal num, s21_decimal num2, s21_decimal *res);
void scale_inc(s21_decimal *num);
void s21_copy(s21_decimal *num, s21_decimal num2);
int loan(s21_decimal *num, int i, int bit_num);
int mul_to_10(s21_decimal *num);
int left_to_div(s21_decimal *num, int shift);

void del(s21_decimal num1, s21_decimal num2, s21_decimal *res,
         s21_decimal *res2);
int less(s21_decimal num, s21_decimal num2);
void left(s21_decimal *num, int shift);
int comparison(
    s21_decimal d1,
    s21_decimal d2);
int greater_num(int a, int b);
int comparison_bits(s21_decimal d1, s21_decimal d2);
void comparison_reverse(int *flag);
int get_num(int *i, int *ind_e, int *ind_tochka, char my_float[24]);
int get_pow(int *i, char my_float[24]);

#endif