#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int a, c=1, b, i;
    scanf("%d %d",&a,&b);
    for (i=0; i<b; i++)
    {
        c*=a;
    }
    printf("%d", c);
    return 0;
}
