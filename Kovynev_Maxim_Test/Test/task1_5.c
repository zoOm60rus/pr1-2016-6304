//Task 1.5
#include "stdio.h"
#include "stdlib.h"

int main()
{
	int array_size;
	printf("Enter array size: ");
	scanf("%d", &array_size);

	int* array;
	array = (int*)malloc(sizeof(int)*array_size);

	for (int count = 0; count < array_size; count++)
	{
		printf("Enter %d element of array: ",count+1);
		scanf("%d", &array[count]);
	}

	int max = array[0];
	int min = array[0];

	for (int count = 0; count < array_size; count++)
	{
		if (array[count] >= max) max = array[count];
		if (array[count] <= min) min = array[count];
	}

	printf("Minimum = %d\n", min);
	printf("Maximum = %d\n", max);
	printf("Maximum - Minimum = %d\n", max - min);
	getchar();
	return 0;
}
