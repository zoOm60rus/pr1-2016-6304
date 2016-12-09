#include <stdlib.h>
#include <string.h>
#include "struct.h"

void sort(MusicalComposition *head)
{
	MusicalComposition *curr_i = head;
	MusicalComposition *curr_j;
	while (curr_i->next)
	{
		curr_j = head;
		while (curr_j->next)
		{
			if (curr_j->year>curr_j->next->year)
			{
				MusicalComposition *temp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
				strcpy(temp->name, curr_j->next->name); strcpy(temp->author, curr_j->next->author); temp->year = curr_j->next->year;
				strcpy(curr_j->next->name, curr_j->name); strcpy(curr_j->next->author, curr_j->author); curr_j->next->year = curr_j->year;
				strcpy(curr_j->name, temp->name); strcpy(curr_j->author, temp->author); curr_j->year = temp->year;
				free(temp);
			}
			curr_j = curr_j->next;
		}
		curr_i = curr_i->next;
	}
}
