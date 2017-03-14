#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* p1, const void* p2)	//реализация функции сравнения для
{								//строк
    return strcmp((char*)p1, (char*)p2);	
}

int main()
{
    int counter=0;
    int i=0;					//счечики и переменные
    int max=0;

    char text[1000];			//массив для текста на ввод
    char str[30];				//массив для искомого слова
    char words[500][1000];		//массив для разбиения текста на слова

    fgets(text, 1000, stdin);		//счет с входного потока в первые
    (*strstr(text, "\n"))='\0';		//два массива
    fgets(str, 30, stdin);

    char* token=strtok(text, " .");		//разделение текста на слова
    while(token!=NULL)
    {
        int numb=strlen(token);			//подсчет длины каждого слова
        strncpy(words[i], token, numb);		//копирование в массив слов
        token=strtok(NULL, " ,");
        i++;
    }

    qsort(words, i, 1000, cmp);			//функция быстрой сортировки

    char* pointer=(char*)bsearch(str, words, i, 1000, cmp);	//функция бинарного
											//поиска
    if(pointer!=NULL)
    {
        printf("exists\n");
    }
    else								//вывод результата поиска
    {
        printf("doesn't exist");
    }

    return 0;
}
