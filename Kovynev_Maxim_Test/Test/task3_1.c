//Task 3.1
#include "stdio.h"
#include "stdlib.h"

int* BruteForceAllVariants(int a, int b, int c)
{
	int* Arrays_Of_Variants;
	Arrays_Of_Variants = (int*)malloc(sizeof(int) * 8);
	Arrays_Of_Variants[0] = a + b + c;
	Arrays_Of_Variants[1] = a + b - c;
	Arrays_Of_Variants[2] = a - b + c;
	Arrays_Of_Variants[3] = a - b - c;
	Arrays_Of_Variants[4] = -a + b + c;
	Arrays_Of_Variants[5] = -a + b - c;
	Arrays_Of_Variants[6] = -a - b + c;
	Arrays_Of_Variants[7] = -a - b - c;

	return Arrays_Of_Variants;
}

void PrintNumbers(int a, int b, int c, int Variant_Signs_Left_Side_Numbers)
{
	switch (Variant_Signs_Left_Side_Numbers)
	{
	case 0: printf("%d+%d+%d", a, b, c); break;
	case 1: printf("%d+%d-%d", a, b, c); break;
	case 2: printf("%d-%d+%d", a, b, c); break;
	case 3: printf("%d-%d-%d", a, b, c); break;
	case 4: printf("-%d+%d+%d", a, b, c);break;
	case 5: printf("-%d+%d-%d", a, b, c);break;
	case 6: printf("-%d-%d+%d", a, b, c);break;
	case 7: printf("-%d-%d-%d", a, b, c);break;
	case 8: printf("-%d-%d-%d", a, b, c);break;
	default: break;
	};


}

int main()
{
	int a, b, c;
	char string;
	int x, y, z;
	int Variant_Signs_Left_Side_Numbers = 0;
	int Variant_Signs_Right_Side_Numbers = 0;

	int* array_1;
	array_1 = (int*)malloc(sizeof(int) * 8);
	int* array_2;
	array_2 = (int*)malloc(sizeof(int) * 8);

	printf("Enter a b c = x y z: ");
	scanf("%d %d %d", &a, &b, &c);
	scanf(" %c ",&string);
	scanf("%d %d %d", &x, &y, &z);

	array_1 = BruteForceAllVariants(a, b, c);
	array_2 = BruteForceAllVariants(x, y, z);
	

	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			if (array_1[i] == array_2[j])
			{
				Variant_Signs_Left_Side_Numbers = i;
				Variant_Signs_Right_Side_Numbers = j;
			}

	if (Variant_Signs_Left_Side_Numbers != 0)
	{
		printf("Option equality:  ");
		PrintNumbers(a, b, c, Variant_Signs_Left_Side_Numbers);
		printf("=");
		PrintNumbers(x, y, z, Variant_Signs_Right_Side_Numbers);
	}
	else printf("No variants!");

	printf("\n");
	getchar();
	return 0;
}
