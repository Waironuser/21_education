#include "../cherlyma_lib/cherlyma.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int flag = 0;
  int sign = 0;

  char str_float[24] = {'\0'};
  sprintf(str_float, "%e", src);
  if (!dst || isnan(src) || isinf(src) || fabs(src) < 1e-28 ||
      fabsf(src) > MAX_FLOAT_TO_CONVERT || fabsf(src) < MIN_FLOAT_TO_CONVERT) {
    flag = 1;
  } else {
    dec_to_null(dst);
    int i = 0;
    if (str_float[0] == '-') {
      sign = 1;
      set_sign(dst, sign);
      i++;
    }
    int ind_e = 0;
    int ind_tochka = 0;
    get_num(&i, &ind_e, &ind_tochka, str_float);
    int pow = get_pow(&i, str_float);
    if (pow < 0) {
      pow *= -1;
      ind_e--;
      while (str_float[ind_e] == '0') {
        ind_e--;
      }
      pow = pow + ind_e - ind_tochka;
      set_scale(dst, pow);
      int mantisa = str_float[ind_tochka - 1] - '0';
      for (int i = ind_tochka + 1; i <= ind_e; i++) {
        mantisa *= 10;
        mantisa += str_float[i] - '0';
      }
      dst->bits[0] = mantisa;
    } else {
      ind_e--;
      while (str_float[ind_e] == '0') {
        ind_e--;
      }
      if ((ind_e - ind_tochka) > pow) {
        set_scale(dst, ind_e - ind_tochka - pow);
        pow = ind_e - ind_tochka;
      }
      int mantisa = str_float[ind_tochka - 1] - '0';
      for (int i = ind_tochka + 1; i <= ind_tochka + pow; i++) {
        mantisa *= 10;
        mantisa += str_float[i] - '0';
      }
      dst->bits[0] = mantisa;
    }
  }
  while (get_scale(*dst) > 7) {
    round_float(dst);
  }
  return flag;
}