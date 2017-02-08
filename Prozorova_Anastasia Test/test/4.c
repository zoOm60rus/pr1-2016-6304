#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
char c;
char* a = (char*)malloc(250*sizeof(char));
int i;
scanf("%c", &c);
scanf("%s", a);
for (i = 0; i<strlen(a); i++){
if (a[i]!=c)
printf("%c", a[i]);
}
return 0;
}
