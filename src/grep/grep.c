#include <ctype.h>
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1000

#define UKN_OPT 0
#define EMPTY_PATTERN 1
#define FILE_OPEN_FAILED 2
#define NO_FILE 3
#define MEM_ALLOC_FAIL 4
#define REG_COMP_FAIL 5

typedef struct {
  int e, i, s, h, o, v, c, l, n, f, multipleFiles, regexOpt;
} Flags;

char *readRegexFromFile(char *filename);
char *strcasestr(const char *haystack, const char *needle);
void checkNewline(char *line);
void prepareSearch(char *searchStr, Flags flags, regex_t *regex,
                   int *compileStatus);
void executeSearch(FILE *filePtr, char *searchStr, Flags flags, char *name,
                   regex_t *regex);
void searchFile(FILE *filePtr, char *searchStr, Flags flags, char *name);
void printErr(int errorType, char *str);
void runGrep(Flags flags, int argc, char **argv);

int main(int argc, char *argv[]) {
  Flags flags = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  runGrep(flags, argc, argv);
  return 0;
}

void runGrep(Flags flags, int argc, char **argv) {
  int opt;
  char *searchStr = NULL;
  while ((opt = getopt(argc, argv, "hoisvclf:ne:")) != -1) {
    switch (opt) {
      case 'i':
        flags.i = 1;
        // flags.o = 0;
        break;
      case 's':
        flags.s = 1;
        break;
      case 'h':
        flags.h = 1;
        // flags.l = 0;
        // flags.c = 0;
        break;
      case 'o':
        flags.o = 1;
        // flags.i = 0;
        // flags.c = 0;
        // flags.l = 0;
        break;
      case 'v':
        flags.v = 1;
        break;
      case 'c':
        flags.c = 1;
        flags.o = 0;  //
        // flags.l = 0;
        // flags.h = 0;
        flags.n = 0;
        break;
      case 'l':
        flags.l = 1;
        // flags.h = 0;
        // flags.c = 0;
        flags.n = 0;  //
        flags.o = 0;  //
        break;
      case 'n':
        flags.n = 1;
        // flags.c = 0;
        // flags.l = 0;
        break;
      case 'f':
        flags.f = 1;
        searchStr = readRegexFromFile(optarg);
        break;
      case 'e':
        flags.regexOpt = 1;
        searchStr = optarg;
        break;
      default:
        printf("Unknown option: -%c\n", opt);
        char str[1] = {(char)opt};
        printErr(UKN_OPT, str);
    }
  }

  if (searchStr == NULL) {
    if (optind < argc) {
      searchStr = argv[optind++];
    } else {
      //   printf(
      //       "Usage: ./my_grep [-i|-s|-v|-c|-l|-n] [-f "
      //       "<regex_file>|-e <regex>] "
      //       "[<file>]\n");
      printErr(EMPTY_PATTERN, NULL);
    }
  }
  if (optind < argc) {
    for (int i = optind; i < argc; i++) {
      flags.multipleFiles++;
    }
  }
  if (flags.h) {
    flags.multipleFiles = 0;
  }
  if (optind < argc) {
    for (int i = optind; i < argc; i++) {
      FILE *filePtr = fopen(argv[i], "r");
      if (filePtr == NULL) {
        if (flags.s == 0) {
          //   printf("Failed to open file %s\n", argv[i]);
          printErr(FILE_OPEN_FAILED, argv[i]);
        }
      }
      searchFile(filePtr, searchStr, flags, argv[i]);
      fclose(filePtr);
    }
  } else {
    searchFile(stdin, searchStr, flags, NULL);
  }
}

char *readRegexFromFile(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    // printf("grep: %s: No such file or directory\n", filename);
    printErr(NO_FILE, filename);
  }

  fseek(file, 0, SEEK_END);
  long fileSize = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *regexStr = (char *)malloc(fileSize + 1);
  if (regexStr != NULL) {
    size_t newLen = fread(regexStr, sizeof(char), fileSize, file);
    regexStr[newLen] = '\0';
  } else {
    // printf("Failed to allocate memory\n");
    printErr(MEM_ALLOC_FAIL, NULL);
    fclose(file);
  }
  fclose(file);
  return regexStr;
}

void searchFile(FILE *filePtr, char *searchStr, Flags flags, char *name) {
  regex_t regex;
  int compileStatus = 0;

  prepareSearch(searchStr, flags, &regex, &compileStatus);
  if (compileStatus) {
    char errorMassage[MAX_LINE_LENGTH];
    regerror(compileStatus, &regex, errorMassage, MAX_LINE_LENGTH);
    // printf("Regular expression compilation error: %s\n", errorMassage);
    printErr(REG_COMP_FAIL, errorMassage);
  }

  executeSearch(filePtr, searchStr, flags, name, &regex);

  if (flags.regexOpt) {
    regfree(&regex);
  }
}

void prepareSearch(char *searchStr, Flags flags, regex_t *regex,
                   int *compileStatus) {
  if (flags.regexOpt) {
    if (flags.i) {
      *compileStatus = regcomp(regex, searchStr, REG_EXTENDED | REG_ICASE);
    } else {
      *compileStatus = regcomp(regex, searchStr, REG_EXTENDED);
    }
  }
}

void executeSearch(FILE *filePtr, char *searchStr, Flags flags, char *name,
                   regex_t *regex) {
  char line[MAX_LINE_LENGTH];
  int match_count = 0;
  int current_flags = 0;

  while (fgets(line, MAX_LINE_LENGTH, filePtr)) {
    current_flags++;

    int match_found;
    if (flags.regexOpt) {
      match_found = (regexec(regex, line, 0, NULL, 0) == 0);
    } else {
      char *match_ptr =
          (flags.i) ? strcasestr(line, searchStr) : strstr(line, searchStr);
      match_found = (match_ptr != NULL);
    }

    if (match_found != flags.v) {
      match_count++;
      if (!flags.c) {
        if (flags.l) {
          if (flags.n) {
            printf("%s:%d\n", name, current_flags);
          } else if (flags.multipleFiles > 1) {
            printf("%s\n", name);
          }
          break;
        }
        if (flags.o) {
          char *match_ptr =
              (flags.i) ? strcasestr(line, searchStr) : strstr(line, searchStr);
          if (match_ptr != NULL) {
            if (flags.multipleFiles > 1) {
              printf("%s:", name);
            }
            if (flags.n) {
              printf("%d:", current_flags);
            }
            printf("%.*s\n", (int)strlen(searchStr), match_ptr);
          }
        } else {
          if (flags.n) {
            if (flags.multipleFiles > 1) {
              printf("%s:%d:%s", name, current_flags, line);
              checkNewline(line);
            } else {
              printf("%d:%s", current_flags, line);
              checkNewline(line);
            }
          } else {
            if (flags.multipleFiles > 1) {
              printf("%s:%s", name, line);
              checkNewline(line);
            } else {
              printf("%s", line);
              checkNewline(line);
            }
          }
        }
      }
    }
  }

  if (flags.c) {
    if (flags.multipleFiles > 1) {
      printf("%s:%d\n", name, match_count);
    } else {
      printf("%d\n", match_count);
    }
  }
}

// void eCase ()

char *strcasestr(const char *haystack, const char *needle) {
  if (haystack == NULL || needle == NULL) {
    return NULL;
  }

  size_t needle_len = strlen(needle);
  if (needle_len == 0) {
    return (char *)haystack;
  }

  while (*haystack) {
    if (strncasecmp(haystack, needle, needle_len) == 0) {
      return (char *)haystack;
    }
    haystack++;
  }

  return NULL;
}

void checkNewline(char *line) {
  int hasNewline = 0;

  int line_length = strlen(line);
  for (int i = 0; i < line_length; i++) {
    if (line[i] == '\n') {
      hasNewline = 1;
    }
  }

  if (!hasNewline) {
    printf("\n");
  }
}

void printErr(int errorType, char *str) {
  switch (errorType) {
    case UKN_OPT:
      printf("Unknown option: -%c\n", str[0]);
      break;
    case EMPTY_PATTERN:
      printf(
          "Usage: ./my_grep [-i|-s|-v|-c|-l|-n] [-f "
          "<regex_file>|-e <regex>] "
          "[<file>]\n");
      break;
    case FILE_OPEN_FAILED:
      printf("Failed to open file %s\n", str);
      break;
    case NO_FILE:
      printf("grep: %s: No such file or directory\n", str);
      break;
    case MEM_ALLOC_FAIL:
      printf("Failed to allocate memory\n");
      break;
    case REG_COMP_FAIL:
      printf("Regular expression compilation error: %s\n", str);
      break;
  }
}
