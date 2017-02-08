#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[100], c;
	int x=0;
	printf("Vvedite stroku, zatem neobhodimiy simvol: \n");
	scanf("%s %c", str, &c);
	int n=strlen(str);
	for (int i=0; i<n; i++)
	{
		if (c == str[i])
			x++;
	}
	printf("%d \n",x);
    return 0;
}
