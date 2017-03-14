#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void * x1, const void * x2)   // функция сравнения элементов массива
{
  return ( *(int*)x2 - *(int*)x1 );              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}

int main()
{
    int *array=(int*)malloc(sizeof(int)*1000); // выделение памяти под массив

    for (int i=0; i<1000;i++)                  // считывание из входного потока элементов массива
        fscanf(stdin,"%d", (array+i));

    int time=clock();                           // переменная, в которой будут храниться данные о времени, потраченном на выполнение программы
    
    qsort(array, 1000, sizeof(int), compare);   // метод быстрой сортировки

    for (int i=0;i<1000; i++)                   // вывод отсортированного массива на экран
        {
        printf("%d ", *(array+i));
        }
        
    printf("\n");                       // переход строки на новую строчку
    printf("%d", (time/CLOCKS_PER_SEC));                  // вывод на экран потраченного времени

    free(array);                                // освобождение памяти
    return 0;
}
