CC = gcc
Flagc = -Wall -Werror -Wextra

s21_cat : cat.o parsing.o flags.o
	$(CC) $(Flagc) cat.o parsing.o flags.o -o s21_cat

cat.o : cat.c 
	$(CC) $(Flagc) -c cat.c -o cat.o

parsing.o : parsing.c 
	$(CC) $(Flagc) -c parsing.c -o parsing.o

flags.o : flags.c 
	$(CC) $(Flagc) -c flags.c -o flags.o

clang_format :
	cp ../../materials/linters/.clang-format .
	clang-format -i *.c *.h
	rm .clang-format

clean : 
	rm -rf *.o s21_cat

rebuild : clean s21_cat

check : rebuild
	sh tests_cat.sh