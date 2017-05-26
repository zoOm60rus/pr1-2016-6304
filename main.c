#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000
int abs(int a);
int compare(const void* b, const void *a){//функция сравнения элементов массива
    return abs(*(int*)a) - abs(*(int*)b);//если результат вычитания равен 0, то числа равны
}
int main()
{
    int a[N]; int i; int time; int time1;
    for (i=0; i<N; i++){
        scanf("%d", &a[i]);
    }
    time = clock();//вычисление времени работы программы
    qsort(a, N, sizeof(int), compare);//быстрая сортировка
    time1 = clock() - time;//вычисление времени сортировки
    for (i=0; i<N; i++){
        printf("%d ",a[i]);
    }
    printf("\n%d", time1);
    return 0;
}
