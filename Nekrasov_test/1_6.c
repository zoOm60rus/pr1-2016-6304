#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
int main() {
	int *a;  // ��������� �� ������
	int i, n, j;
	int sr = 0;
	scanf("%d", &n);
	// ��������� ������
	a = (int*)malloc(n*n*sizeof(int));
	// ���� ��������� �������
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			a[i, j] = 0;
		}
	}
	a[0, 0] = a[n, n] = 1;
	a[0, n] = a[n, 0] = 2;
return 0;
}