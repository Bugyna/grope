#include "util.h"

void append_line(char* line, char c, unsigned int column)
{
	line = realloc(line, column+1);
	line[column] = c;
}

char* read_file(const char* filename, int* len)
{
	FILE* file = fopen(filename, "r");
	fseek(file, 0, SEEK_END);
	*len = ftell(file);
	fseek(file, 0, SEEK_SET);
	char* buff = malloc(*len);
	char c;
	for (int i = 0; (c = fgetc(file)) != EOF; i++) {
		buff[i] = c;
	}
	fclose(file);
	return buff;
}

void check(MATCH* matches, unsigned int* match_len, KEYWORD keyword, char* text, char* filename, unsigned int file_len)
{
	bool ret = false;
	unsigned int row = 1, column = 0;
	char* line = malloc(2);
	int i = -1;
	for (;;) {
		i++;
		if (i >= file_len) { return; }
		append_line(line, text[i], column++);
		if (text[i] == '\n') { row++; column = 0; line = realloc(line, 2); continue; }
		if (keyword.word[0] == text[i]) {
			for (int j = 1; j < keyword.len; j++) {
				i++;
				append_line(line, text[i], column++);
				if (keyword.word[j] != text[i]) {
					ret = false; break;
				}
				else {
					ret = true;
				}
			}
			
			if (ret) {
				append_match(&matches, match_len, keyword.word, filename, row, column, line);
				i++;
			}	
		}
	}
}


int main(int argc, char** argv)
{
	unsigned int match_len = 1;
	MATCH* matches = malloc(20*sizeof(MATCH));
	KEYWORD keyword;
	int file_len = 0;
	if (argc == 1) {
		printf("Please supply keyword");
		return 1;
	}
	else if (argc == 2) {
		printf("Please supply files");
		return 1;
	}

	keyword.len = strlen(argv[1]);
	keyword.word = malloc(keyword.len+1);
	keyword.word = argv[1];
	printf("keyword: %s\n", keyword.word);
	
	for (int i = 2; i < argc; i++) {
		char* text = read_file(argv[i], &file_len);
		printf("%s\n", argv[i]);
		check(matches, &match_len, keyword, text, argv[i], file_len);
	}
	printf("done\n");
	return 0;
}
