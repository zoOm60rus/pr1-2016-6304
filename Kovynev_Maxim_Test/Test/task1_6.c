//Task 1.6
#include "stdio.h"
#include "stdlib.h"

int main()
{
	int array_size;
	printf("Enter array size: ");
	scanf("%d", &array_size);

	int** array;
	array = (int**)malloc(array_size * sizeof(int*));

	for (int count_i = 0; count_i < array_size; count_i++)
	{
		array[count_i] = (int*)malloc(array_size * sizeof(int));
		for (int count_j = 0; count_j < array_size; count_j++)
			array[count_i][count_j] = 0;
	}

	array[0][0] = 1;
	array[array_size - 1][0] = 2;
	array[array_size - 1][array_size - 1] = 1;
	array[0][array_size - 1] = 2;

	for (int count_i = 0; count_i < array_size; count_i++)
	{
		for (int count_j = 0; count_j < array_size; count_j++)
			printf("%d ", array[count_i][count_j]);
		printf("\n");
	}

	getchar();
	return 0;
}
