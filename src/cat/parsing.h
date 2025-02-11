#ifndef PARSING_H
#define PARSING_H

#include <getopt.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} Flags;

Flags inputFlags(int argc, char* argv[], int* correctFlags);
char* getFilename(int argc, char* argv[], int* filesIndex, int* countFiles);

#endif