#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int i;
	int min;
	int max;
	int len;
	int dif;
	scanf("%d", &len);
	int* array = (int*)malloc(len*sizeof(int));
	for (i = 0; i<len; i++)
	{
		scanf("%d", &array[i]);
	}
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
	printf("%d", dif);
	return 0;
}
