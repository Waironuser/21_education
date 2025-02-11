#include <stdio.h>
#include <string.h>

#include "flags.h"
#include "parsing.h"

int main(int argc, char *argv[]) {
  int correctFlags = 1, countFiles = 0;
  int filesIndex[10000];
  char *noCorrectFile = getFilename(argc, argv, filesIndex, &countFiles);
  Flags flags = inputFlags(argc, argv, &correctFlags);
  if (!correctFlags)
    printf("usage: cat [-belnstuv] [file ...]\n");
  else if (strcmp(noCorrectFile, "") && correctFlags)
    printf("cat: %s: No such file or directory\n", noCorrectFile);
  else
    runForFile(flags, argv, filesIndex, countFiles);
  return 0;
}
