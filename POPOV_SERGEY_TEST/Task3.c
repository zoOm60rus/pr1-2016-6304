#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int i = 0;
	char c;
	char* str = (char*)malloc(256*sizeof(char));
	int j = 0;
	scanf ("%c", &c);
	scanf ("%s", str);
	for (i; i<strlen(str); i++)
	{
		if (str[i]==c)
		j++;
	}
	printf("%d\n", j);
	return 0;
}
