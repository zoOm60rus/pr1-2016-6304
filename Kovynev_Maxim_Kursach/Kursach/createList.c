#include "struct.h"
#include <stdlib.h>
#include <string.h>
MusicalComposition* createMusicalComposition(char *name, char* author, int year)
{
        MusicalComposition* rr = (MusicalComposition*)malloc(sizeof(MusicalComposition));
        strcpy(rr->name, name);
        strcpy(rr->author, author);
        rr->year = year;
        rr->next = NULL;
        rr->prev = NULL;
        return rr;
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
        MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
        MusicalComposition *prev = head;
        MusicalComposition *current;
        int i;
        for ( i = 1; i < n; ++i)
        {
                current = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
                current->prev = prev;
                prev->next = current;
                prev = current;
        }
        return head;
}

