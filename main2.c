#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[100], b[100];
    int i=1, j=0;
    scanf("%s", a);
    while (a[i]!='\0')
    {
        if (i%2==1)
        {
            b[j]=a[i];
            j++;
        }
        i++;
    }
    printf("%s", b);
    return 0;
}
