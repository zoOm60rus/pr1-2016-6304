#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int main()
{
    int a[N]; int i; int bt; int et;
    for (i=0; i<N; i++){
        scanf("%d", &a[i]);
    }
    bt = clock();
    qsort(a, N, sizeof(int), compare);
    et = clock() - bt;
    for (i=0; i<N; i++){
        printf("%d ",a[i]);
    }
    printf("\n%d", et);
    return 0;
}
