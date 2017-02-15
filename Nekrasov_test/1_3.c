#include <string.h>
#include <stdio.h> 
#define MAX 100
int main(int argc, char* argv[])
{
    char  s[MAX];
    char  substr[MAX];
    int   n = 0;   // кол-во вхождений
    char* temp;
    gets(s);
    gets(substr);
    temp = s;
    while (temp = strstr(temp, substr) )  // найти первое совпадение в temp
    {
        n++;
        temp++;   // перейти на следующий символ для сравнения
    }
    printf("N = %d", n);
    getchar();
    return 0;
}
