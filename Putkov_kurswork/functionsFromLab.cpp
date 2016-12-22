#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct MusicalComposition {
	char name[80];
	char author[80];
	int year;
	struct MusicalComposition* next;
	struct MusicalComposition* prev;
};

typedef struct MusicalComposition MusicalComposition;

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

	for (int i = 1; i < n; ++i)
	{

		current = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
		current->prev = prev;
		prev->next = current;
		prev = current;
	}
	return head;
}

void push(MusicalComposition* head, MusicalComposition* element)
{

	while (head->next)
		head = head->next;

	head->next = element;
	element->prev = head;
	element->next = NULL;
}

void removeEl(MusicalComposition*head, char*name_for_remove)
{

	MusicalComposition *ptr;
	ptr=head;
	while (head)
	{

		if (strcmp(head->name, name_for_remove) == 0)
		{
			if (head->next == NULL)
			{

				head->prev->next = NULL;
				head=ptr;
				return;
			}
			else if (head->prev == NULL)
			{

				head->next->prev = NULL;
				head=ptr;
				return;
			}

			head->prev->next = head->next;
			head->next->prev = head->prev;
			head=ptr;
			break;
		}
		head = head->next;
	}
}

int count(MusicalComposition*head)
{

	int count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return count;
}

void print_names(MusicalComposition *head)
{

	while (head)
	{
		printf("%s\n", head->name);
		head = head->next;
	}
}
