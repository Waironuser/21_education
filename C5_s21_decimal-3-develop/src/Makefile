CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
CHECK_FLAGS = -lcheck

UNAME:=$(shell uname -s)
ifeq ($(UNAME),Linux)
	LDFLAGS=-lcheck -lsubunit -lm -lrt -lpthread
	OPEN_CM=xdg-open
endif
ifeq ($(UNAME),Darwin)
	LDFLAGS=-lcheck -lm
	OPEN_CM=open
	GCOV_ERROR_IGNORE=--ignore-errors range
endif

all: s21_decimal.a

clean:
	-rm *.a ./s21_decimal_lib/*.o ./lavadaja_lib/funcs/*.o ./sobektof_lib/funcs/*.o ./cherlyma_lib/funcs/*.o
	-rm *.gcno ./s21_decimal_lib/*.gcno ./lavadaja_lib/funcs/*.gcno ./sobektof_lib/funcs/*.gcno ./cherlyma_lib/funcs/*.gcno
	-rm *.gcda ./s21_decimal_lib/*.gcda ./lavadaja_lib/funcs/*.gcda ./sobektof_lib/funcs/*.gcda ./cherlyma_lib/funcs/*.gcda
	-rm *.info
	-rm *_test
	-rm -r s21_gcov
	-rm *.c
	-rm *_tests.c

CT = cherlyma_test
LT = lavadaja_test
ST = sobektof_test

# -L$(HOME)/my_check/lib -I$(HOME)/my_check/include

test: s21_decimal.a
	checkmk tests/cherlyma/tests.check > cherlyma_tests.c
	checkmk tests/lavadaja/tests.check > lavadaja_tests.c
	checkmk tests/sobektof/tests.check > sobektof_tests.c
	${CC} ${CFLAGS} cherlyma_tests.c $^ -o ${CT} ${LDFLAGS}
	${CC} ${CFLAGS} lavadaja_tests.c $^ -o ${LT} ${LDFLAGS}
	${CC} ${CFLAGS} sobektof_tests.c $^ -o ${ST} ${LDFLAGS}
	-./${CT}
	-./${LT}
	-./${ST}

CHERLYMA_SRC = $(wildcard ./cherlyma_lib/funcs/*.c)
LAVADAJA_SRC = $(wildcard ./lavadaja_lib/funcs/*.c)
SOBEKTOF_SRC = $(wildcard ./sobektof_lib/funcs/*.c)
S21_DECIMAL_SRC = $(wildcard ./s21_decimal_lib/*.c)

ALL_SRC = $(LAVADAJA_SRC) $(SOBEKTOF_SRC) $(S21_DECIMAL_SRC) $(CHERLYMA_SRC)

ALL_OBJ = $(ALL_SRC:.c=.o)

s21_decimal.a: $(ALL_OBJ)
	@ar rcs $@ $^

gcov_report: CFLAGS += $(GCOV_FLAGS) 
gcov_report: test
	lcov --capture --directory . --output-file coverage.info $(GCOV_ERROR_IGNORE)
	lcov --remove coverage.info '*/tests/*' '*/lavadaja_lib/*' '*/sobektof_lib/*' '*/cherlyma_lib/*' --output-file coverage.info
	genhtml coverage.info --output-directory s21_gcov
	$(OPEN_CM) s21_gcov/index.html &

clang-format:
	cp ../materials/linters/.clang-format .
	clang-format -i lavadaja_lib/funcs/*.c
	clang-format -i sobektof_lib/funcs/*.c
	clang-format -i s21_decimal_lib/*.c
	rm .clang-format

main: s21_decimal.a
	cp s21_decimal.a libs21_decimal.a
	$(CC) ./tests/testing_main.c -L. -ls21_decimal -o ./tests/compiled_tests -lm
	./tests/compiled_tests
