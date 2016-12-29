#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct MusicalComposition
{
        char* name;
        char* author;
        int year;
        struct MusicalComposition *next;
        struct MusicalComposition *previous;
}MusicalComposition;

extern MusicalComposition* head;

