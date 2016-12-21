#include "struct.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "function.h"

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
        int i=1;
        for (i = 1; i < n; ++i)
        {
                current = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
                current->prev = prev;
                prev->next = current;
                prev = current;
        }
        return head;
}


MusicalComposition* add() {
        clear();
        int length = 0;
        while (length <= 0)
        {
                printf("Enter the number of adding elements: ");
                scanf("%d", &length);
                if (length <= 0)
                        printf("\nError - number of elements is a positive integer!\n\n");
        }

        char **names = (char**)malloc(sizeof(char*)*length);
        char **authors = (char**)malloc(sizeof(char*)*length);
        int *years = (int*)malloc(sizeof(int)*length);

        int i=0;
        for (i = 0; i < length; ++i)
        {
                printf("\nEnter element %d: - name, author, year (using spaces):\n", i + 1);
                char name[80];
                char author[80];

                scanf("%s %s %d", name, author, &years[i]);

                names[i] = (char*)malloc(sizeof(char*)*(strlen(name) + 1));
                authors[i] = (char*)malloc(sizeof(char*)*(strlen(author) + 1));

                strcpy(names[i], name);
                strcpy(authors[i], author);
        }
        return createMusicalCompositionList(names, authors, years, length);
}

