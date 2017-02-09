#include <stdio.h>
int main () {
int a,b;
int j = 1;
int i;
scanf ("%i %i",&a, &b);
for (i = 0; i<b; i++)
j = j*a;
printf ("%d\n", j);
return 0;
}
