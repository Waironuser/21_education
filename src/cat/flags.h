#ifndef FLAGS_H
#define FLAGS_H

#include <stdio.h>
#include <string.h>

#include "parsing.h"

typedef struct {
  int isLastStrEmpty;
  int isSkipStr;
  int isNeedEntr;
} Args;

void runForFile(Flags flags, char* argv[], int* filesIndex, int countFiles);
void output(Flags flags, char* currStr, int* countStr, Args args);

#endif