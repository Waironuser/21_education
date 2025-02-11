#include "../cherlyma.h"

void dec_to_null(s21_decimal *num) {
  for (int i = 0; i < 128; i++) {
    set_bit(num, i, 0);
  }
}

int correct(s21_decimal num) {
  int flag = 1;
  for (int i = 126; i >= 120 && flag; i--) {
    if (get_bit(num, i) == 1) flag = 0;
  }
  for (int i = 96; i <= 111 && flag; i++) {
    if (get_bit(num, i) == 1) flag = 0;
  }
  if (get_scale(num) > 28) flag = 0;
  return flag;
}

int s21_zero(s21_decimal num) {
  int res = 1;
  for (int i = 0; i < 96 && res; i++) {
    if (get_bit(num, i) != 0) res = 0;
  }
  return res;
}

int multiplication(s21_decimal num, s21_decimal num2, s21_decimal *res) {
  int flag = 0;
  big_decimal tmp1 = {{0, 0, 0, 0, 0, 0, 0, 0}};
  int scale = get_scale(num) + get_scale(num2);
  big_decimal value = {{0, 0, 0, 0, 0, 0, 0, 0}};
  decimal_to_bigdecimal(num2, &value);
  big_decimal tmp = {{0, 0, 0, 0, 0, 0, 0, 0}};
  decimal_to_bigdecimal(num2, &tmp);
  set_scale(&num2, 0);
  set_sign(&num2, 0);
  for (int i = 0; i < 96; i++) {
    tmp = value;
    if (get_bit(num, i)) {
      for (int j = 0; j < i; j++) {
        left_for_big(&tmp, 1);
      }
      plus_bigdec(tmp1, tmp, &tmp1);
    }
  }
  while (overflow(tmp1) && scale) {
    round_float_big(&tmp1);
    scale--;
  }
  if (overflow(tmp1)) flag = 1;
  bigdecimal_to_decimal(res, tmp1);
  set_scale(res, scale);
  while (get_scale(*res) > 28) {
    round_float(res);
  }
  return flag;
}

void set_bit(s21_decimal *num, int index, int bit) {
  int num_ind = index / 32;
  int num_bit = index % 32;
  if (bit == 1) {
    num->bits[num_ind] |= (1u << num_bit);
  } else {
    num->bits[num_ind] &= (~((1u) << num_bit));
  }
}

int get_bit(s21_decimal num, int x) {
  int n_int = x / 32;
  int n_num = x % 32;
  int res = (num.bits[n_int] & (1u << n_num)) >> x;
  return res;
}

int get_scale(s21_decimal num) {
  int scale = 0;
  for (int i = 119; i >= 112; i--) {
    scale <<= 1;
    scale |= get_bit(num, i);
  }
  return scale;
}

void decimal_to_bigdecimal(s21_decimal value_1, big_decimal *value_2) {
  for (int i = 0; i < 96; i++) {
    set_bit_big(value_2, i, get_bit(value_1, i));
  }
}

int left_for_big(big_decimal *num, int shift) {
  int flag = 1;
  for (int j = 0; j < shift; j++) {
    int tmp = get_bit_big(*num, 31);
    int tmp1 = get_bit_big(*num, 63);
    int tmp2 = get_bit_big(*num, 95);
    int tmp3 = get_bit_big(*num, 127);
    int tmp4 = get_bit_big(*num, 159);
    int tmp5 = get_bit_big(*num, 191);
    int tmp6 = get_bit_big(*num, 223);
    for (int i = 0; i < 9; i++) {
      num->bits[i] <<= 1;
    }
    set_bit_big(num, 32, tmp);
    set_bit_big(num, 64, tmp1);
    set_bit_big(num, 96, tmp2);
    set_bit_big(num, 128, tmp3);
    set_bit_big(num, 160, tmp4);
    set_bit_big(num, 192, tmp5);
    set_bit_big(num, 224, tmp6);
  }
  return flag;
}

int plus_bigdec(big_decimal num, big_decimal num2, big_decimal *res) {
  int tmp = 0;
  int per = 0;
  int flag = 1;
  int finish = 255;
  for (int i = 0; i < finish; i++) {
    tmp = get_bit_big(num, i) + get_bit_big(num2, i) + per;
    if (tmp == 2) {
      tmp = 0;
      per = 1;
    } else if (tmp == 3) {
      tmp = 1;
      per = 1;
    } else if (tmp == 0) {
      tmp = 0;
      per = 0;
    } else if (tmp == 1) {
      tmp = 1;
      per = 0;
    }
    set_bit_big(res, i, tmp);
  }
  return flag;
}

int overflow(big_decimal value) {
  int flag = 0;
  for (int i = 255; i > 95 && !flag; i--) {
    if (get_bit_big(value, i)) flag = 1;
  }
  return flag;
}

void round_float_big(big_decimal *num) {
  unsigned int remainder = 0;
  unsigned int integer = 0;
  big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
  big_decimal temp = {{0, 0, 0, 0, 0, 0, 0, 0}};
  big_div_to_10(num, &remainder);
  temp = *num;
  big_div_to_10(&temp, &integer);
  if (remainder > 5) {
    plus_bigdec(*num, one, num);
  } else if (remainder == 5 && integer % 2) {
    plus_bigdec(*num, one, num);
  }
}

void bigdecimal_to_decimal(s21_decimal *value_1, big_decimal value_2) {
  for (int i = 0; i < 112; i++) {
    set_bit(value_1, i, get_bit_big(value_2, i));
  }
}

void round_float(s21_decimal *num) {
  unsigned int remainder = 0;
  unsigned int integer = 0;
  s21_decimal one = {{1, 0, 0, 0}};
  s21_decimal temp = {{0, 0, 0, 0}};
  s21_div_to_10(num, &remainder);
  temp = *num;
  s21_div_to_10(&temp, &integer);
  if (remainder > 5) {
    plus(*num, one, num);
  } else if (remainder == 5 && integer % 2) {
    plus(*num, one, num);
  }
}

void set_bit_big(big_decimal *num, int index, int bit) {
  int num_ind = index / 32;
  int num_bit = index % 32;
  if (bit == 1) {
    num->bits[num_ind] |= (1u << num_bit);
  } else {
    num->bits[num_ind] &= (~((1u) << num_bit));
  }
}

int get_bit_big(big_decimal num, int x) {
  int n_int = x / 32;
  int n_num = x % 32;
  int res = (num.bits[n_int] & (1u << n_num)) >> x;
  return res;
}

void big_div_to_10(big_decimal *num, unsigned *rest) {
  uint64_t p_rest = 0;
  int div = 10;
  *rest = 0;
  for (int i = 7; i >= 0; i--) {
    p_rest = *rest * 4294967296 + (unsigned int)num->bits[i];
    num->bits[i] = p_rest / div;
    *rest = p_rest - div * (unsigned int)num->bits[i];
  }
}

void s21_div_to_10(s21_decimal *num, unsigned *rest) {
  uint64_t p_rest = 0;
  int div = 10;
  int scale = get_scale(*num);
  int sign = get_sign(*num);
  set_scale(num, 0);
  set_sign(num, 0);
  *rest = 0;
  for (int i = 3; i >= 0; i--) {
    p_rest = *rest * 4294967296 + (unsigned int)num->bits[i];
    num->bits[i] = p_rest / div;
    *rest = p_rest - div * (unsigned int)num->bits[i];
  }
  if (scale) {
    set_scale(num, (scale - 1));
  }
  set_sign(num, sign);
}

int plus(s21_decimal num, s21_decimal num2, s21_decimal *res) {
  int tmp = 0;
  int per = 0;
  int flag = 1;
  int finish = 111;
  for (int i = 0; i < finish; i++) {
    tmp = get_bit(num, i) + get_bit(num2, i) + per;
    if (tmp == 2) {
      tmp = 0;
      per = 1;
    } else if (tmp == 3) {
      tmp = 1;
      per = 1;
    } else if (tmp == 0) {
      tmp = 0;
      per = 0;
    } else if (tmp == 1) {
      tmp = 1;
      per = 0;
    }
    set_bit(res, i, tmp);
  }
  return flag;
}

void set_scale(s21_decimal *num, int scl) {
  for (int i = 112; i < 120; i++) {
    set_bit(num, i, scl & 1);
    scl >>= 1;
  }
}

void set_sign(s21_decimal *num, int sig) { set_bit(num, 127, sig); }

int get_sign(s21_decimal num) { return get_bit(num, 127); }

int scale_equalize(s21_decimal *num, s21_decimal *num2) {
  s21_decimal *big = NULL;
  s21_decimal *small = NULL;
  s21_decimal tmp = {{0, 0, 0, 0}};
  int per = 0;
  int out = 1;
  if (get_scale(*num) != get_scale(*num2)) {
    ;
    if (get_scale(*num) > get_scale(*num2)) {
      big = num;
      small = num2;
      per = 1;
    } else {
      big = num2;
      small = num;
    }
    int scaleB = get_scale(*big);
    int scaleS = get_scale(*small);
    // int scale = scaleB - scaleS;
    increase(big, small, &tmp, &scaleS);
    set_scale(&tmp, scaleS);
    int scale2 = scaleB - scaleS;
    while (scale2) {
      round_float(big);
      set_scale(big, scaleS);
      scale2--;
    }
    if (per) {
      num = big;
      num2 = &tmp;
    } else {
      num = &tmp;
      num2 = big;
    }
    out = 0;
  } else if (get_scale(*num) > 28 && get_scale(*num2) > 28) {
    while (get_scale(*num) > 28 && get_scale(*num2) > 28) {
      round_float(num);
      round_float(num2);
    }
  }
  return out;
}

int add_and_sign(s21_decimal num, s21_decimal num2, s21_decimal *res, int sign,
                 int sign2) {
  int result = 0;
  int tmp = 0;
  s21_decimal tmp1 = num;
  if (sign == 0 && sign2 == 0) {
    tmp = plus(num, num2, res);
    if (tmp == 0) result = 1;
  } else if (sign == 1 && sign2 == 1) {
    tmp = plus(num, num2, res);
    if (tmp == 0) result = 2;
    set_sign(res, 1);
  } else if (sign == 1 && sign2 == 0) {
    set_sign(&tmp1, 0);
    if (s21_is_less(tmp1, num2)) {
      minus(num2, num, res);
    } else {
      minus(num, num2, res);
      if (!s21_zero(*res)) set_sign(res, 1);
    }
  } else if (sign == 0 && sign2 == 1) {
    tmp1 = num2;
    set_sign(&tmp1, 0);
    if (!s21_is_less(tmp1, num)) {
      minus(num2, num, res);
      if (!s21_zero(*res)) set_sign(res, 1);
    } else {
      minus(num, num2, res);
    }
  }
  return result;
}

int first_unzero_bit(s21_decimal num) {
  int flag = 0;
  for (int i = 111; i > 95 && !flag; i--) {
    if (get_bit(num, i)) flag = 1;
  }
  return flag;
}

void increase(s21_decimal *big, s21_decimal *small, s21_decimal *tmp,
              int *scaleS) {
  int scaleB = get_scale(*big);
  int scale = scaleB - *scaleS;
  int flag = 1;
  while (scale && flag) {
    for (int i = 0; i < 4; i++) {
      tmp->bits[i] = small->bits[i];
    }
    scale_inc(small);
    if (!first_unzero_bit(*small)) {
      s21_copy(tmp, *small);
      *scaleS = get_scale(*small);
      scale--;
    } else {
      round_float(small);
      *scaleS = get_scale(*small);
      flag = 0;
    }
  }
}

void minus(s21_decimal num, s21_decimal num2, s21_decimal *res) {
  int tmp = 0;
  int bit_num = 0;
  for (int i = 0; i < 112; i++) {
    bit_num = get_bit(num, i);
    if (bit_num == 0 && get_bit(num2, i) == 1) {
      bit_num = loan(&num, i, bit_num);
    }
    tmp = bit_num - get_bit(num2, i);
    set_bit(res, i, tmp);
  }
}

void scale_inc(s21_decimal *num) {
  if ((get_scale(*num) + 1) < 29) {
    if (!first_unzero_bit(*num)) {
      set_scale(num, (get_scale(*num) + 1));
      mul_to_10(num);
    }
  } else {
    while (get_scale(*num) > 28) {
      round_float(num);
    }
  }
}

void s21_copy(s21_decimal *num, s21_decimal num2) {
  for (int i = 0; i < 102; i++) {
    set_bit(num, i, get_bit(num2, i));
  }
}

int loan(s21_decimal *num, int i, int bit_num) {
  for (int j = i + 1; j < 112 && !bit_num; j++) {
    if (get_bit(*num, j) == 1) {
      set_bit(num, j, 0);
      bit_num = 2;
      for (int x = j - 1; x > i; x--) {
        set_bit(num, x, 1);
      }
    }
  }
  return bit_num;
}

int mul_to_10(s21_decimal *num) {
  int flag = 0;
  s21_decimal temp = {{0b1010, 0, 0, 0}};
  // s21_decimal tmp = temp;
  s21_decimal tmp1 = {{0, 0, 0, 0}};
  for (int i = 0; i < 102; i++) {
    s21_decimal tmp = temp;
    if (get_bit(*num, i)) {
      for (int j = 0; j < i; j++) {
        left_to_div(&tmp, 1);
      }
      plus(tmp1, tmp, &tmp1);
    }
  }
  s21_copy(num, tmp1);
  return flag;
}

int left_to_div(s21_decimal *num, int shift) {
  int flag = 1;
  for (int j = 0; j < shift; j++) {
    int tmp = get_bit(*num, 31);
    int tmp1 = get_bit(*num, 63);
    int tmp2 = get_bit(*num, 95);
    for (int i = 0; i < 5; i++) {
      num->bits[i] <<= 1;
    }
    set_bit(num, 32, tmp);
    set_bit(num, 64, tmp1);
    set_bit(num, 96, tmp2);
  }
  return flag;
}

void del(s21_decimal num1, s21_decimal num2, s21_decimal *res,
         s21_decimal *res2) {
  s21_decimal q = {{0, 0, 0, 0}};
  s21_decimal s = {{0, 0, 0, 0}};
  int i = 0;
  if (!s21_zero(num2)) {
    set_sign(&num1, 0);
    set_sign(&num2, 0);
    s21_decimal tmp1 = num1;
    s21_decimal tmp2 = num2;
    s21_decimal temp = tmp2;
    dec_to_null(res);
    dec_to_null(res2);
    while (!s21_zero(tmp1) && !less(tmp1, num2)) {
      tmp2 = num2;
      i = 0;
      while (less(tmp2, tmp1)) {
        left_to_div(&tmp2, 1);
        i++;
      }
      dec_to_null(&q);
      if (i <= 1) {
        set_bit(&q, 0, 1);
      } else {
        set_bit(&q, 0, 0);
        set_bit(&q, 1, 1);
        left(&q, i - 2);
      }
      plus(s, q, &s);
      temp = num2;
      left_to_div(&temp, i - 1);
      s21_sub(tmp1, temp, &tmp1);
    }
    plus(*res, s, res);
    dec_to_null(&temp);
    multiplication(num2, *res, &temp);
    minus(num1, temp, res2);
  } else {
    dec_to_null(res);
    dec_to_null(res2);
  }
}

int less(s21_decimal num, s21_decimal num2) {
  int less = 0;
  int flag = 0;
  int sign1 = get_sign(num);
  int sign2 = get_sign(num2);
  if (sign1 == 0 && sign2 == 0) {
    for (int i = 111; i >= 0 && !flag; i--) {
      if (get_bit(num, i) < get_bit(num2, i)) {
        less = 1;
        flag = 1;
      } else if (get_bit(num, i) > get_bit(num2, i)) {
        less = 0;
        flag = 1;
      }
    }
  }
  for (int i = 111; i >= 0 && !flag; i--) {
    if (get_bit(num, i) != get_bit(num2, i)) {
      less = 0;
      flag = 1;
    }
  }
  return less;
}

void left(s21_decimal *num, int shift) {
  for (int j = 0; j < shift; j++) {
    int tmp = get_bit(*num, 31);
    int tmp1 = get_bit(*num, 63);
    for (int i = 0; i < 3; i++) {
      num->bits[i] <<= 1;
    }
    set_bit(num, 32, tmp);
    set_bit(num, 64, tmp1);
  }
}

int comparison(
    s21_decimal d1,
    s21_decimal d2) {  // 0, 1, 2, если dec1 = dec2, dec1 > dec2, dec1 < dec2
  int flag = 0;
  int scale_dif = (get_scale(d1) - get_scale(d2));
  scale_equalize(&d1, &d2);
  flag = greater_num(!get_sign(d1), !get_sign(d2));
  if (flag == 0) {
    if (scale_dif >= 0) {
      flag = comparison_bits(d1, d2);
    } else {
      scale_dif = -scale_dif;
      flag = comparison_bits(d2, d1);
      comparison_reverse(&flag);
    }
    if (get_sign(d1) && get_sign(d2)) {
      comparison_reverse(&flag);
    }
  } else {
    if (d1.bits[0] == 0 && d1.bits[1] == 0 && d1.bits[2] == 0 &&
        d2.bits[0] == 0 && d2.bits[1] == 0 && d2.bits[2] == 0) {
      flag = 0;
    }
  }
  return flag;
}

int greater_num(int a, int b) {
  int flag = 0;
  if (a > b) {
    flag = 1;
  } else if (a < b) {
    flag = 2;
  } else if (a == b) {
    flag = 0;
  }
  return flag;
}

int comparison_bits(s21_decimal d1, s21_decimal d2) {
  int bit1 = 0;
  int bit2 = 0;
  int flag = 0;
  for (int i = 95; i >= 0 && !flag; --i) {
    bit1 = get_bit(d1, i);
    bit2 = get_bit(d2, i);
    if (bit1 > bit2) {
      flag = 1;
    } else if (bit1 < bit2) {
      flag = 2;
    }
  }
  return flag;
}

void comparison_reverse(int *flag) {
  if (*flag == 1) {
    *flag = 2;
  } else if (*flag == 2) {
    *flag = 1;
  }
}

int get_num(int *i, int *ind_e, int *ind_tochka, char my_float[24]) {
  int num = 0;
  for (; my_float[*i] != 'e'; *i += 1) {
    if (my_float[*i] == '.') *ind_tochka = *i;
    num *= 10;
    num += my_float[*i] - '0';
  }
  *ind_e = *i;
  *i += 1;
  return num;
}

int get_pow(int *i, char my_float[24]) {
  int pow = 0;
  int pow_sign = 0;
  if (my_float[*i] == '-') {
    pow_sign = 1;
    *i += 1;
  } else
    *i += 1;
  for (; my_float[*i]; *i += 1) {
    pow *= 10;
    pow += my_float[*i] - '0';
  }
  if (pow_sign) pow *= -1;
  return pow;
}
