#include <stdio.h>
#include "struct.h"

/*Функция печати имен*/
void print_names(MusicalComposition *head)
{
        /* Двигаем указатель до последнего элемента */
        while (head)
        {
                /*Печать имени*/
                printf("%s\n", head->name);
                head = head->next;
        }
}
