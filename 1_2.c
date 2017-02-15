#include <stdio.h>
#include <string.h>
#include <iostream.h>
int main()
{
char str [256];
int i;
gets (str);
for (i=0;i<256;i+2){
	printf("%s\n",str);
	}
return 0;
}