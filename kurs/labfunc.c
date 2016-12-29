#include "struct.h"

MusicalComposition* createMusicalComposition (char* name, char* author, int year)
{
        MusicalComposition* composition = (MusicalComposition*)malloc(sizeof(MusicalComposition));
        composition->name = name;
        composition->author = author;
        composition->year = year;
        composition->next = NULL;
        composition->previous = NULL;
        return composition;
}

MusicalComposition* createMusicalCompositionList (char** array_names, char** array_authors, int* array_years, int n)
{
        if (n == 0)
                return NULL;
        MusicalComposition* head = createMusicalComposition (array_names[0], array_authors[0], array_years[0]);
        MusicalComposition* tmp = head, buf;
        for (int i = 1; i < n; i++)
        {
                tmp->next = createMusicalComposition (array_names[i], array_authors[i], array_years[i]);
                tmp->next->previous = tmp;
                tmp = tmp->next;
        }
        return head;
}

void push (MusicalComposition* element)
{
        if (head == NULL)
                head = element;
        else
        {
                MusicalComposition* tmp = head;
                while (tmp->next != NULL)
                        tmp = tmp->next;
                tmp->next = element;
                element->previous = tmp;
        }
}

void removeEl ( char* name_for_remove)
{
        MusicalComposition *tmp = head;
        while (tmp != NULL)
        {
                if (strcmp(tmp->name, name_for_remove) == 0)
                {
                        if (tmp == head)
                        {
                                head=head->next;
                                if (head != NULL)
                                        head->previous = NULL;
                        }
                        else
                                tmp->previous->next = tmp->next;
                }
                tmp = tmp->next;
        }
}

int count ()
{
        MusicalComposition* tmp = head;
        int count = 0;
        while (tmp != NULL)
        {
                count++;
                tmp = tmp->next;
        }
        return count;
}

void print_names()
{
        MusicalComposition *tmp = head;
        int number = 1;
        if (tmp == NULL)
                printf ("There are no compositions\n");
        else
                while (tmp != NULL)
                {
                        printf ("%d. %s %p\n", number++, tmp->name, tmp);
                        tmp = tmp->next;
                }
}

