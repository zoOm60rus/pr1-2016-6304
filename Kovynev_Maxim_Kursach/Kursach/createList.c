#include "struct.h"
#include <stdlib.h>
#include <string.h>

/* Функция создания и инициализации нового экземпляра структуры "MusicalComposition" */
MusicalComposition* createMusicalComposition(char *name, char* author, int year)
{
        /* Выделим память для нового экземпляра структуры "MusicalComposition" */
        MusicalComposition* rr = (MusicalComposition*)malloc(sizeof(MusicalComposition));
        /* Проинициализируем поля параметрами, переданными в функцию */
        strcpy(rr->name, name);
        strcpy(rr->author, author);
        rr->year = year;
        rr->next = NULL;
        rr->prev = NULL;
        /* Вернем указатель на новый экземпляр структуры "MusicalComposition" */
        return rr;
}

/* Функция создания списка  */
MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
        /* Указатель на первый элемент, который вернет функция*/
        MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
        /* Указатели для движения по списку */
        MusicalComposition *prev = head;
        MusicalComposition *current;
        int i;
        /* Заполенение элментов*/
        for ( i = 1; i < n; ++i)
        {
                current = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
                /* Двигаем указатели*/
                current->prev = prev;
                prev->next = current;
                prev = current;
        }
        return head;
}

