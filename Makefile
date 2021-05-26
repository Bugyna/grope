CC=clang
CFLAGS= -Wall -Wextra -pedantic

main: *.c *h
	$(CC) main.c -o grope
