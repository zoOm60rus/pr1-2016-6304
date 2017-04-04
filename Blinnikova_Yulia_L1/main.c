#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int funccmp(const void * x1, const void * x2)//сравнение элементов массива
{
        return strcmp((char*)x1,(char*)x2);
}


int main (){
char text [1000];//текст
char str [30];//искомое слово
fgets(text,1000,stdin);
fgets(str,30,stdin);

char *ptr = strtok(text," .");//выполняет поиск лексем в строке. Последовательность вызовов этой функции разбивают строку на лексемы, которые представляют собой последовательности символов, разделенных символами разделителями.
char keep[1000][1000];
int i=0;
while(ptr)
{
        strcpy(keep[i], ptr);
        ptr = strtok(NULL," .");
        i++;
}

qsort(keep, i, 1000, funccmp);//быстрая сортировка

char *x = (char*) bsearch(str, keep, i, 1000, funccmp);//двоичный поиск в массиве
if (x != NULL)
        {printf("exists");}
else printf("doesn't exist");

return 0;
}

