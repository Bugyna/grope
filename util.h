#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
	unsigned int len;
	char* word;
} KEYWORD;

typedef struct {
	char* word, filename;
	unsigned int row, column;
} MATCH;


void append_match(MATCH** matches, unsigned int* match_len, char* word, char* filename, unsigned int row, unsigned int column)
{
	printf("match found at: %d. %d\n", row, column);
//	printf("match_len i: %d", *match_len);
//	unsigned int i = *match_len;
//	matches[i]->row = row;
//	matches[i]->column = column;
//	matches[i]->filename = *filename;
//	matches[i]->word = word;
//	match_len = match_len + 1;
//	matches = realloc(matches, *match_len+1);
}

