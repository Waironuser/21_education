#include "parsing.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Flags inputFlags(int argc, char* argv[], int* correctFlags) {
  Flags flags = {0, 0, 0, 0, 0, 0};
  struct option longOptions[] = {{"number-nonblank", 0, 0, 'b'},
                                 {"number", 0, 0, 'n'},
                                 {"squeeze-blank", 0, 0, 's'},
                                 {0, 0, 0, 0}};
  int currFlag = getopt_long(argc, argv, "benstvET", longOptions, 0);
  for (; currFlag != -1;
       currFlag = getopt_long(argc, argv, "benstvET", longOptions, 0)) {
    switch (currFlag) {
      case 'b':
        flags.b = 1;
        break;
      case 'e':
        flags.e = 1;
        flags.v = 1;
        break;
      case 'v':
        flags.v = 1;
        break;
      case 'E':
        flags.e = 1;
        flags.v = 1;
        break;
      case 'n':
        flags.n = 1;
        break;
      case 's':
        flags.s = 1;
        break;
      case 't':
        flags.t = 1;
        flags.v = 1;
        break;
      case 'T':
        flags.t = 1;
        flags.v = 1;
        break;
      default:
        *correctFlags = 0;
        break;
    }
  }
  return flags;
}

char* getFilename(int argc, char* argv[], int* filesIndex, int* countFiles) {
  char* wrongFile = "";
  for (int i = 1; i < argc; ++i) {
    // for (size_t j = 0; j < strlen(argv[i]); ++j) {
    if (argv[i][0] != '-') {
      filesIndex[*countFiles] = i;
      *countFiles += 1;
    }
  }
  for (int i = 0; i < *countFiles; ++i) {
    FILE* file = fopen(argv[filesIndex[i]], "r");
    if (file == NULL) wrongFile = argv[filesIndex[i]];
    break;
    fclose(file);
  }
  return wrongFile;
}
