//Task 2.2
#include "stdio.h"
#include "stdlib.h"

int main()
{
	int array_size;
	int value = 1;
	printf("Enter array size: ");
	scanf("%d", &array_size);

	int** a;
	a = (int**)malloc(array_size * sizeof(int*));

	for (int count_i = 0; count_i < array_size; count_i++)
	{
		a[count_i] = (int*)malloc(array_size * sizeof(int));
		for (int count_j = 0; count_j < array_size; count_j++)
		{
			a[count_i][count_j] = value;
			value++;
		}
		value = value - array_size + 1;
	}



	for (int count_i = 0; count_i < array_size; count_i++)
	{
		for (int count_j = 0; count_j < array_size; count_j++)
			printf("%d ", a[count_i][count_j]);
		printf("\n");

	}
	getchar();
	return 0;
}
