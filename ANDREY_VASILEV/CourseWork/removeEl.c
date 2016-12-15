#include <stdlib.h>

#include "struct.h"  //Подключаем файл с объявлением структуры

void removeEl(MusicalComposition* head, char* name_for_remove)
{
	MusicalComposition *hold = NULL; //Создаем переменную и 
   	hold = head;			     //сохраняем в ней "head".
    	while(head)	//Цикл выполняется пока указатель 
    	{	       //станет равен "NULL".
		if (strcmp(head->name, name_for_remove)==0) //Сравниваем строки 
         	{	
			if (head->next == NULL){   //Если элемент последний, то текущим
				head = head->prev; //становится предыдущий элемент, а
				head->next = NULL; //его указатель на след. становится NULL				break;
			} else if (head->prev == NULL){	//Если удаляемый элемент первый, то
				head->next->prev = NULL;	//"hold" присваивается следующий
				hold = head->next;	//элемент списка, т.е.новое начало списка.
			} else {
//В случае, когда элемент является не крайним, перемещаем указатели данным образом
				head->next->prev = head->prev;	
				head->prev->next = head->next;
			}
								
		}
		head = head->next;	/*Если строки не совпали, делаем текущим указатель на след. структуру */
	}
    	head = hold;  	//Возвращаем "head" сохраненное значение
}





