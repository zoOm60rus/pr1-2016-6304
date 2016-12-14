#include <stdio.h>
#include <stdlib.h>
#include <string.h>	    //Подключаем заголовочные файлы с
#include "struct.h"		//объявлением структуры и с 
#include "func.h"		//прототипом "createMusicalCompositionList"
MusicalComposition* AddToBegin(MusicalComposition* head)
{
	int i, k;												//Считываем количество
	printf("Количество добавляемых элементов в начало: ");	//добавляемых элементов
	scanf("%d", &k);
	char** names = (char**)malloc(sizeof(char*)*k);			//Выделяем память под
	char** authors = (char**)malloc(sizeof(char*)*k);		//списки имен, авторов
	int* years = (int*)malloc(sizeof(int)*k);				//и годов.
    for (i=0;i<k;i++)								
    {												//С помощью цикла заполняем
        char name[80];								//списки значениями
        char author[80];
        printf("[%d] Композиция, автор и год: ", i+1);
		scanf("%s", name);
		scanf("%s", author);
		scanf("%d", &years[i]);
        names[i] = (char*)malloc(sizeof(char) * (strlen(name)+1));
        authors[i] = (char*)malloc(sizeof(char) * (strlen(author)+1));
        strcpy(names[i], name);
        strcpy(authors[i], author);
    }
	MusicalComposition* NewHead;		//Создаем "новую" голову списка
	NewHead= createMusicalCompositionList(names, authors, years, k);
	MusicalComposition* temp = NewHead;	//Заполняем новый мини список
	while(NewHead->next){				//с помощью созданной раннее функции
		NewHead = NewHead->next;		//Передвигаемся по списку до конечн. эл.
	}										
	NewHead->next = head;			//Связываем конец мини списка с началом основного
	head->prev = NewHead;			//
	return temp;				//Возвращаем указатель на начало нового дополненного списка
}



