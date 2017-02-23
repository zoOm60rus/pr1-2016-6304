//Task 1.3
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

	int count = 0;
	for (int i = 0; i < strlen(s); i++)
		if (s[i] == c[0]) count++;

	printf("Amount of %c - %d",c[0], count);
	printf("\n");
	getchar();


	return 0;
}
