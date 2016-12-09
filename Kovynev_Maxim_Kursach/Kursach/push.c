#include "struct.h"
#include <stdlib.h>
void push(MusicalComposition* head,MusicalComposition* element)
{
        while (head->next)
                head = head->next;
        head->next = element;
        element->prev = head;
        element->next = NULL;
}


