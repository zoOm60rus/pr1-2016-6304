#include "struct.h"

/*Функция подсчета элементов списка:*/
int count(MusicalComposition*head)
{
        /*Переменная count - счетчик*/
        int count = 0;
        /* Двигаем указатель до последнего элемента */
        while (head)
        {
                count++;
                head = head->next;
        }
        return count;
};

