//Task 1.2
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main()
{
	char letter;
	int count = 0;
	printf("Enter string: ");
	while ((letter = getchar()) != '\n')
	{
		count++;
		if ((count % 2) != 1) printf("%c", letter);
	}
	printf("\n");
	getchar();
	return 0;
}
