//Task 1.1
#include "stdio.h"
#include "stdlib.h"
float stepen(int a, int b)
{
	int c = a;
	if ((a == 0) && (b < 0))
	{
		c = -1;
		return c;
	}
	for (int i = 1; i < abs(b); i++)
		c = c*a;
	
	return c;
}

int main()
{
	int a = 0;
	int b = 0;
	float c = 0;
	printf("Enter a, b: ");
	scanf("%d %d", &a, &b);
	c = stepen(a, b);
	if (b < 0) c = 1.0 / c;
	if (c!=-1.0)
	printf("%d^%d = %f\n",a,b,c);
	else printf("Error\n");

	getchar();
	return 0;
}
