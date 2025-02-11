#include "flags.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parsing.h"

void runForFile(Flags flags, char* argv[], int* filesIndex, int countFiles) {
  for (int i = 0; i < countFiles; ++i) {
    Args args = {0, 0, 0};
    FILE* file = fopen(argv[filesIndex[i]], "r");
    char currStr[1000];
    int countStr = 1;
    while (fgets(currStr, sizeof(currStr), file) != NULL) {
      output(flags, currStr, &countStr, args);
      if (currStr[0] == '\n' || currStr[0] == '$')
        args.isLastStrEmpty = 1;
      else
        args.isLastStrEmpty = 0;
      args.isSkipStr = 0, args.isNeedEntr = 0;
    }
    fclose(file);
  }
}

void output(Flags flags, char* currStr, int* countStr, Args args) {
  if (flags.s == 1 && args.isLastStrEmpty && currStr[0] == '\n') {
    args.isSkipStr = 1;
  }
  if (flags.b) {
    if (currStr[0] != '\n') {
      printf("%6d\t", *countStr);
      *countStr += 1;
    } else if (!args.isSkipStr && currStr[0] == '\n' && flags.e)
      printf("      \t");
  }
  if (!flags.b && flags.n &&
      ((currStr[0] != '\n' && flags.s) ||
       (!args.isLastStrEmpty && currStr[0] == '\n' && flags.s) || !flags.s)) {
    printf("%6d\t", *countStr);
    ++*countStr;
  }
  for (size_t i = 0; i < strlen(currStr); ++i) {
    char ch = currStr[i];
    if (flags.v && ch != '\n' && ch != '\t' && !args.isSkipStr) {
      if (ch <= 31 && ch > 0) {
        ch += 64;
        printf("^%c", ch);
      } else if (ch == 127) {
        printf("^?");
      } else if (ch < 0) {
        ch = ch & 0x7F;
        printf("M-%c", ch);
      }
    }
    if (flags.e && !args.isSkipStr && ch == '\n' && !args.isSkipStr)
      printf("$\n");
    else if (flags.t && currStr[0] != '\n' && ch == '\t' && !args.isSkipStr) {
      printf("^I");
    } else if (!args.isSkipStr)
      putchar(ch);
  }
}
