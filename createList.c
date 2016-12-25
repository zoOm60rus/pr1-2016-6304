#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "abc.h"


MusicalComposition* createMusicalComposition(char* name, char* author, int year){
    MusicalComposition* p = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    p->prev = NULL;
    p->next = NULL;
    strcpy(p->name, name);
    strcpy(p->author, author);
    p->year = year;

    return p;
}


MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n){
    int i;
    MusicalComposition* tmp = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
    MusicalComposition* head = tmp;
    for (i=1; i<n; i++)
    {
        tmp->next = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
        tmp->next->prev = tmp;
        tmp = tmp->next;
    }

    return head;
}
