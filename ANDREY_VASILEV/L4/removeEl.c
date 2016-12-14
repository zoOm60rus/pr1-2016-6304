#include <stdlib.h>

#include "struct.h"  //Подключаем файл с объявлением структуры

void removeEl(MusicalComposition* head, char* name_for_remove)
{
    MusicalComposition *hold = NULL; //Создаем переменную и 
    hold = head;			//сохраняем в ней "head".
    while(head)										 //Цикл выполняется пока указатель не станет
    {												 //станет равен "NULL".
         if (strcmp(head->name, name_for_remove)==0) //Сравниваем строки и если они совпадают, то
         {												//Присваиваем след. элементу. предыдущего 
			 head->prev->next = head->next;				//указатель на следующий элемент текущего
			 head->next->prev = head->prev;				//и предыдущему элементу следующего - 
			 free(head);								//указатель на предыдущий эл. текущего.
             break;										//Освобождаем память
         }
        head = head->next;				//Делаем текущим указатель на след. структуру
    }
    head = hold;  	//Возвращаем "head" исходное значение
}





