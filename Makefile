CC=clang
CFLAGS= -Wall -Wextra -pedantic

main: *.c
	$(CC) main.c -o main