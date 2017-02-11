#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int len,min,max,dif;
	int i = 0;
	int array[256];
	char c;

	while ((c = getchar()) != '\n')
	{
		array[i] = atoi(&c);
		i++;
	}
	len = i;

	min = array[0];
	max = array[0];
	for (i = 1; i<len; i++)
	{
		if (array[i]>max)
		{
			max = array[i];
		}
		if (array[i]<min)
		{
			min = array[i];
		}
	}
	dif = max - min;
	printf("%d\n", dif);
	return 0;
}
