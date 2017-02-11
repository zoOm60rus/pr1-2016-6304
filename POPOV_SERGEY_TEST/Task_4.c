#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char c;
	char* str = (char*)malloc(256*sizeof(char));
	int i;
	scanf("%c", &c);
	scanf("%s", str);
	for (i = 0; i<strlen(str); i++)
	{
		if (str[i]!=c)
		printf("%c", str[i]);
	}
	printf("\n");
	return 0;
}
