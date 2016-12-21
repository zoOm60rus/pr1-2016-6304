#include "struct.h"
#include <stdlib.h>
/*Функция добавления элемента в конец списка*/
void push(MusicalComposition* head,MusicalComposition* element)
{
        /* Двигаем указатель до последнего элемента */
        while (head->next)
                head = head->next;
        head->next = element;
        element->prev = head;
        element->next = NULL;
}


