#include <stdio.h>
#include "struct.h"

void print_names(MusicalComposition *head)
{
        while (head)
        {
                printf("%s\n", head->name);
                head = head->next;
        }
}
