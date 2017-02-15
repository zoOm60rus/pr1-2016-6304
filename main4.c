#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[100], k[100];
    char b;
    int i=0;
    int j=0;
    scanf("%s %c", a, &b);
    for (i=0; i<strlen(a); i++)
    {
        if (a[i]!=b)
        {
            k[j]=a[i];
            j++;
        }
    }
    printf ("%s", k);
    return 0;
}
