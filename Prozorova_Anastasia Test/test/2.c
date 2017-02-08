#include <stdio.h>
#include <stdlib.h>

int main() {
int i = 0;
char* a = (char*)malloc(250*sizeof(char));
char c;
int k;
while ((c = getchar()) != '\n'){
a[i] = c;
i++;
}
for (k=1; k<i; k=k+2)
printf("%c", a[k]);
return 0;
}
