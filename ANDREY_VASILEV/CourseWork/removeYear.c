#include <stdlib.h>
#include <stdio.h>
#include "struct.h"		//Подключаем файл с объявлением структуры

MusicalComposition* removeYear(MusicalComposition* head)
{
	MusicalComposition *i, *start = head;		//Создаем вспомогательную переменную
	printf("Удалить элементы, чей год меньше: "); //которая будет указывать на начало 
	int k;										  //списка
	scanf("%d", &k);							  //Вводим год
	while(head){							   //Цикл будет выполнятся, пока указатель не ноль
		if (head->year < k){				//Если год данного элемента меньше введенного, то
			if (head->next == NULL){		//в зависимости от расположения элемента, данный
				head = head->prev;			//элемент будет удален при помощи изменения 
				head->next = NULL;			//указателей на следующую и предыдущ. структуры
				break;
			} else if (head->prev == NULL){	//Если удаляемый элемент первый, то
				head->next->prev = NULL;	//"start" присваивается следующий
				start = head->next;			//элемент списка, т.е. новое начало списка.
			} else {
				head->next->prev = head->prev;	
				head->prev->next = head->next;
			}
		}
		head = head->next;		//Передвигаемся по списку на один элемент
	}
	return start;			//Возвращаем указатель на новое (если изменилось) начало списка 
}






