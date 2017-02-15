#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
int main() {
	int *a;  // указатель на массив
	int i, n;
	int sr = 0;
	scanf("%d", &n);
	// Выделение памяти
	a = (int*)malloc(n*sizeof(int));
	// Ввод элементов массива
	for (i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
		sr = max(a[i], sr);
		printf("%d", sr);
	}
return 0;
}
