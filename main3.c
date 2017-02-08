#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[100];
    char b;
    int i;
    int j=0;
    scanf("%s %c", a, &b);
    for (i=0; i<strlen(a); i++)
    {
        if (a[i]==b)
        {
            j++;
        }
    }
    printf ("%d", j);
    return 0;
}
