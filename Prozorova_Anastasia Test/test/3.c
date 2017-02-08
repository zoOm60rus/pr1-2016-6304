#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
int i;
char c;
char* a = (char*)malloc(100*sizeof(char));
int k = 0;
scanf ("%c", &c);
scanf ("%s", a);
for (i = 0; i<strlen(a); i++){
if (a[i]==c)
k++;
}
printf("%d\n", k);
return 0;
}

