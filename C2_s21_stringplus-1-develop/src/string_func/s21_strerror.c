#include "../s21_string.h"
#include "s21_err_codes.h"

char *s21_strerror(int errnum) {
  char *result = s21_NULL;
  char *errors[] = S21_ERR_MASS;
  static char buf[100];
  if (errnum >= 0 && errnum <= S21_ERR_SIZE) {
    result = errors[errnum];
  } else {
    s21_sprintf(buf, "Unknown error %d", errnum);
    result = buf;
  }
  return result;
}