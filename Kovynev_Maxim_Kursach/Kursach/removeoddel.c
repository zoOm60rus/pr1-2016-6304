#include <stdlib.h>
#include <string.h>
#include "struct.h"


void removeEl(MusicalComposition* head, char*name_for_remove)
{
	while (head)
	{
	if (strcmp(head->name, name_for_remove)==0)
	{
		if (head->next==NULL)
		{
		head->prev->next=NULL;
		return;
		}
		else if (head->prev==NULL)
		{
		head->next->prev=NULL;
		return;
		}

		head->prev->next=head->next;
		head->next->prev=head->prev;
		break;
	}
	head=head->next;
}
}

void removeoddel(MusicalComposition *head)
{
	int i = 0;
	while (head)
	{
		if (((++i) % 2) == 0) removeEl(head, head->name);
		head = head->next;
	}
}

