#include "struct.h"
#include "labfunc.h"

void DeleteS ()
{
        MusicalComposition* tmp = head;
        while (tmp != NULL)
        {
                for(int i=0; tmp->author[i]!='\0';i++ )
                        if (tmp->author[i]=='s' || tmp->author[i]=='S' )
                                removeEl(tmp->name);
                tmp=tmp->next;
        }
}

void Sort ()
{
	MusicalComposition** arr = (MusicalComposition**)malloc(sizeof(MusicalComposition*));
	MusicalComposition* tmp = head;	
	MusicalComposition* temp;
	int lenght;
	for (int i=0; tmp != NULL; i++, tmp = tmp->next, lenght = i)
	{
		arr = (MusicalComposition**)realloc(arr, sizeof(MusicalComposition*)*(i+1));
		arr[i] = tmp;
	}
	for (int i = 0; i < (lenght-1); i++)
	{
		for (int j = i; j < lenght; j++)
		{
			if (strcmp(arr[i]->name, arr[j]->name) > 0)
			{
				temp = arr[i];
                                arr[i] = arr[j];
                                arr[j] = temp;
			}
		}
	}
	head = arr[0];
	arr[0]->previous = NULL;
	arr[0]->next = arr[1];
	for (int i=1; i < (lenght-1); i++)
	{
		arr[i]->previous = arr[i-1];
		arr[i]->next = arr[i+1];
	}
	arr[lenght-1]->previous = arr[lenght-3];
	arr[lenght-1]->next = NULL;
}
