#include <stdlib.h>
#include <string.h>
#include "struct.h"

/*Функция удаления элемента*/
void removeEl(MusicalComposition* head, char*name_for_remove)
{
	/* Двигаем указатель до последнего элемента */
	while (head)
	{
	if (strcmp(head->name, name_for_remove)==0)
	{
		/* Если элемент, который надо удалить последний то разрываем связь с предыдущим */
		if (head->next==NULL)
		{
		head->prev->next=NULL;
		return;
		}
		/* Если элемент, который надо удалить первый то разрываем связь со следующим*/
		else if (head->prev==NULL)
		{
		head->next->prev=NULL;
		return;
		}
		
		/* Меняем значения поля next у предыдущего элемента */
		head->prev->next=head->next;
		/* Меняем значение поля prev у следующего элемента */
		head->next->prev=head->prev;
		break;
	}
	head=head->next;
}
}

/*Функция удаления нечетныых элементов списка*/
void removeoddel(MusicalComposition *head)
{
	int i = 0;
	/* Двигаем указатель до последнего элемента */
	while (head)
	{
		/*Если номер элемента нечетен, то передаем функции removeEl имя элемента*/
		if (((++i) % 2) == 0) removeEl(head, head->name);
		head = head->next;
	}
}

