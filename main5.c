#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10];
    int i, min=0, max, r;
    scanf ("%d",&a[0]);
    max=min=a[0];
    for (i=1; i<10; i++)
    {
        scanf ("%d", &a[i]);
        if (a[i]<min)
        {
            min=a[i];
        }
        if (a[i]>max)
        {
            max=a[i];
        }
    }
    r=max-min;
    printf("%d", r);
    return 0;
}
