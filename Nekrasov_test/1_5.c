#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
int main() {
	int *a;  // ��������� �� ������
	int i, n;
	int sr = 0;
	scanf("%d", &n);
	// ��������� ������
	a = (int*)malloc(n*sizeof(int));
	// ���� ��������� �������
	for (i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
		sr = max(a[i], sr);
		printf("%d", sr);
	}
return 0;
}
