#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int a, b, i;
    float c=1, t=1;
    scanf("%d %d",&a,&b);
    if (b>0)
    {
        for (i=0; i<b; i++)
        {
            c*=a;
        }
    }
    if (b<0)
    {
        b=abs(b);
        for (i=0; i<b; i++)
        {
            t=t/a;
        }
        c=t;
    }
    printf("%f", c);
    return 0;
}
