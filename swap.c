#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "abc.h"


MusicalComposition* split_and_swap (MusicalComposition* head, int n) {
int i = 0; int j = 0;
MusicalComposition** spisok = (MusicalComposition**)malloc((n+1)*sizeof(MusicalComposition*));
for (i = 0; i<n; i++)
    spisok[i] = (MusicalComposition*)malloc(sizeof(MusicalComposition*));

    for (i = 0; i<n; i++){
    spisok[i] = head;
    head = head->next;
}

    for (i = 0; i<n-1; i = i + 2){
    spisok[i+1]->next = NULL;
    spisok[i]->prev = NULL;
    change(spisok[i], spisok[i+1]);
    }

    for (i = 1; i<n-1; i = i + 2){
    spisok[i]->next = spisok[i+1];
    spisok[i+1]->prev = spisok[i];
}



 head = spisok[0];
 return head;
}
