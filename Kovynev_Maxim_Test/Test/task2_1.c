//Task 2.1
#include "stdio.h"
#include "stdlib.h"

int main()
{
	int array_size; 

	printf("Enter array size: ");
	scanf("%d",&array_size );

	int* array;
	array = (int*)malloc(sizeof(int)*array_size);
	
	for (int i = 0; i < array_size; i++)
	{
		printf("Enter %d element: ", i+1);
		scanf("%d", &array[i]);
	}

	int max_current = array[0];
	int value = array[0];
	int max_length = 0;
	int length = 1;

	for (int i = 1; i < array_size; i++)
	{
		if (array[i] == array[i - 1])
			length++;
		else
		{
			if (length > max_length)
			{
				max_length = length;
				max_current = value;
			}
			length = 1;
			value = array[i];
		}
	}

	if (length > max_length)
	{
		max_length = length;
		max_current = value;
	}

	if (max_length == 1)
		printf("No similar neighboring values!\nMaximum length - 1");
	else
		printf("%d (%d)\n", max_length, max_current);
	getchar();
	return 0;
}
