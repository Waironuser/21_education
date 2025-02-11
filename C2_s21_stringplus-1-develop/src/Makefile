LIBRARY 			= s21_string.a
FUNC_FILES 			= string_func/s21_*.c
FUNC_CSHARP_FILES	= csharp_func/s21_*.c
OBJ					= s21_*.o
FUNC_TEST			= tests/test_s21_*.c
OBJ_TEST			= test_s21_*.o
OUT_TEST			= string_test
REPORT_FILE 		= report/index.html

UNAME_S := $(shell uname -s)

CC			= gcc
CFLAGS		= -c -std=c11 -Wall -Werror -Wextra
L_FLAGS		= -std=c11 -Wall -Werror -Wextra
COVER_FLAG  = --coverage
LIB_FLAGS 	= ar rcs

ifeq ($(UNAME_S), Linux)
	OS_SPECIFIC_FLAGS 				= -lcheck -lsubunit -lm
	OS_SPECIFIC_GCOV_REPORT 		= lcov_branch_coverage=1
	OS_SPECIFIC_GCOV_REPORT_HTML 	= genhtml_branch_coverage=1
else ifeq ($(UNAME_S), Darwin)
	OS_SPECIFIC_FLAGS 				= -lcheck
    OS_SPECIFIC_GCOV_REPORT 		= branch_coverage=1
    OS_SPECIFIC_GCOV_REPORT_HTML 	= branch_coverage=1
endif

all: clean s21_string.a

s21_string.a: build.o
	$(LIB_FLAGS) $(LIBRARY) $(OBJ)
	rm -fr $(OBJ)

test: test_file
	./$(OUT_TEST)
	-rm -rf *.gc* *.info $(OUT_TEST) $(OBJ_TEST) $(OBJ) $(LIBRARY)

leaks_test: test_file
	leaks -atExit -- ./$(OUT_TEST)
	-rm -rf *.gc* *.info $(OUT_TEST) $(OBJ_TEST) $(OBJ) $(LIBRARY)

test_file: s21_string.a_for_test build_test.o
	$(CC) $(L_FLAGS) $(COVER_FLAG) $(OBJ_TEST) tests/main.c -L. $(LIBRARY) $(OS_SPECIFIC_FLAGS) -o $(OUT_TEST)

s21_string.a_for_test: build_object_for_test.o
	$(LIB_FLAGS) $(LIBRARY) $(OBJ)
	rm -fr $(OBJ)

build.o:
	$(CC) $(CFLAGS) $(FUNC_FILES) $(FUNC_CSHARP_FILES)

build_object_for_test.o:
	$(CC) $(CFLAGS) $(COVER_FLAG) $(FUNC_FILES) $(FUNC_CSHARP_FILES)

build_test.o:
	$(CC) $(CFLAGS) $(FUNC_TEST)

gcov_report: test_file
	./$(OUT_TEST)
	lcov -t "test" -o string.info -c -d . --rc $(OS_SPECIFIC_GCOV_REPORT)
	genhtml -o report string.info --rc $(OS_SPECIFIC_GCOV_REPORT_HTML)
	-rm -rf *.gc* *.info $(OUT_TEST) $(OBJ_TEST) $(OBJ) $(LIBRARY)
	open $(REPORT_FILE)

build_o: $(FUNC_FILES)
	$(CC) $(CFLAGS) $(FUNC_FILES)

clang_format:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i $(FUNC_FILES) $(FUNC_CSHARP_FILES) $(FUNC_TEST) string_func/*.h tests/*.h tests/main.c s21_string.h
	clang-format -n $(FUNC_FILES) $(FUNC_CSHARP_FILES) $(FUNC_TEST) string_func/*.h tests/*.h tests/main.c s21_string.h
	rm .clang-format

rebuild: clean all

clean:
	rm -rf $(OBJ) $(OUT_TEST) $(OBJ_TEST) $(LIBRARY) $(OUT_TEST) *.gc* report/ *.info