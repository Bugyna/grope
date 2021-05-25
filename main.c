#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

typedef struct {
	unsigned int len;
	char* word;
} KEYWORD;

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

bool check(char* text, int file_len, KEYWORD keyword)
{
	bool ret = false;
	for (int i = 0; i <= file_len; i++) {
		printf("%d\n", text[i]);
		if (keyword.word[0] == text[i]) {
			printf("letter match at %d\n", i);
			
			for (int j = 1; j < keyword.len; j++) {
				if (keyword.word[j] != text[i+j]) {
					ret = false;
				}
				else {
					printf("letter match at %d\n", i+j);
					ret = true;
				}
			}
			
			if (ret) {
				printf("match found at: %d\n", i);
				return true;
			}
			
		}
	}
	return false;
}

int main(int argc, char** argv)
{
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
		// printf("text: %s\n", text);
		printf("filelen: %d\n", file_len);
		printf("check: %d\n", check(text, file_len, keyword));
	}
	printf("done\n");
	return 0;
}