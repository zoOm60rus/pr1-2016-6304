//Task 1.4
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
int main()
{
	char s[100];
	printf("Enter string: ");
	fgets(s, 100, stdin);

	char c[1];
	printf("Enter any character: ");
	scanf("%c", c);

	printf("String without %c - ", c[0]);
	int count = 0;
	for (int i = 0; i < strlen(s); i++)
		if (s[i] != c[0]) printf("%c",s[i]);

	getchar();


	return 0;
}
