#ifndef S21_STRING_H
#define S21_STRING_H

#define s21_NULL ((void *)0)
typedef unsigned long int s21_size_t;
#include <stdlib.h>
// lavadaja

char *s21_strchr(const char *str, int c);
s21_size_t s21_strlen(const char *str);
char *s21_strtok(char *str, const char *delim);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strrchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strerror(int errnum);

int s21_atoi(const char *str);

// meribali

int s21_sprintf(char *str, const char *format, ...);
int s21_sscanf(const char *str, const char *format, ...);

int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memchr(const void *str, int c, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);

void *s21_memmove(void *dest, const void *src, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strcpy(char *dest, const char *src);

int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);

char *s21_strncat(char *dest, const char *src, s21_size_t n);

s21_size_t s21_strcspn(const char *str1, const char *str2);

void *to_upper(const char *str);
void *to_lower(const char *str);
void *insert(const char *src, const char *str, s21_size_t start_index);
void *trim(const char *src, const char *trim_chars);

#endif
