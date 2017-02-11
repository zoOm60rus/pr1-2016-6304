#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char c;
	int i = 0;
	while ((c = getchar()) != '\n')
	{
		i++;
		if ((i % 2) != 1)
		{
			printf("%c", c);
		}
	}
	printf("\n");
  return 0;
}
