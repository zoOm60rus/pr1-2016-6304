#include <stdio.h>
#include <stdlib.h>
char* input(char* in)
{
	char* buffer = (char*)malloc(sizeof(char)*80);
	char ch;
	int k = 0;
	while((ch = getchar()) != '\n'){
	buffer[k] = ch;
	k++;
	}
	buffer[k] = '\0';
	in = buffer;
	free(buffer);
	return in;
}
