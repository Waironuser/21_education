CC = gcc
Flagc = -Wall -Werror -Wextra

s21_grep : grep.o
	$(CC) $(Flagc) grep.o -o s21_grep

grep.o : grep.c 
	$(CC) $(Flagc) -c grep.c -o grep.o

clang_format :
	cp ../../materials/linters/.clang-format .
	clang-format -n *.c
	rm .clang-format

clean : 
	rm -rf *.o s21_grep

rebuild : clean s21_grep

check : rebuild
	sh tests_grep.sh
