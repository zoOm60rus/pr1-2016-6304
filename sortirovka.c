#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "abc.h"

void change (MusicalComposition* a, MusicalComposition* b){
    char stroka[80];
    int count;
    strcpy(stroka, a->name);
    strcpy(a->name, b->name);
    strcpy (b->name, stroka);
    strcpy(stroka, a->author);
    strcpy(a->author, b->author);
    strcpy (b->author, stroka);
    count = a->year;
    a->year = b->year;
    b->year = count;
}


MusicalComposition* go_next (int n, MusicalComposition* head){
    int i;
    for(i = 0; i<n; i++)
        head = head->next;

    return head;
}



void sort (MusicalComposition* head, int n){
int i, j;
    for(i = 0; i<n; i++)
        for(j = i; j<n; j++)
            if (strcmp((go_next(i, head))->name, (go_next(j, head))->name)>0)
                change(go_next(i, head), go_next(j, head));

}
