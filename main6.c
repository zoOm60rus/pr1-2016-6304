#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, j;
    scanf("%d", &n);
    int** b;
    b=(int**)malloc(n*sizeof(int*));
    for (i=0; i<n; i++)
    {
        b[i]=(int*)malloc(n*sizeof(int));
        for (j=0; j<n; j++)
        {
            b[i][j]=0;
        }
    }
    b[0][0]=1;
    b[0][n-1]=2;
    b[n-1][0]=2;
    b[n-1][n-1]=1;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
