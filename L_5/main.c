#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const int N = 1000;
void bubble_sort (int *);
void swap (int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
 
int compare (const void * a, const void *b)
{
	return ( *(int*)a - *(int*)b);
}
 int main ()
{
	int arr1 [N], arr2 [N];
	for (int i = 0; i < N ;i++)
	{
		scanf ("%d", arr1+i);
	}
	clock_t t1, t2;
	time (&t1);
	t1 = clock();
	bubble_sort(arr1);
	t2 = clock();
	t2-=t1;
	clock_t t3, t4;
	t3 = clock ();
	qsort (arr2, N, sizeof(int), compare);	
	t4 = clock ();
	t4-=t3;
	for (int i=0; i < N; i++)
		printf ("%d ", *(arr1+i));
	printf ("\n%f\n%f", (double)t2/CLOCKS_PER_SEC, (double)t4/CLOCKS_PER_SEC);
	return 0;
}
 
void bubble_sort (int *arr)
{
	for (int i=1; i < N; i++)
	{
		for (int j=0; j < N-i; j++)
		{
			if (*(arr+j) > *(arr+j+1))
			{
				swap (arr+j, arr+j+1);
			}
		}
	}
}
