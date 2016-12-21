#include "stdlib.h"
#include "struct.h"
#include "stdio.h"
#include "string.h"
#include "createlist.h"

void clear()
{
	system("@cls||clear");
}

void pause()
{
	printf("Press any key to continue...\n");
	getchar();
	getchar();
}

void print_names(MusicalComposition *head)
{
	MusicalComposition *current = head;
        int i = 0;
        while (current)
        {
		printf(" %d. %s %s %d\n", i++, current->name, current->author, current->year);
		current = current->next;
        }
}

void push(MusicalComposition* head)
{
        char name_for_push[80];
        char author_for_push[80];
        int year_for_push;
        printf("Enter name, author and year (using spaces):\n");
        scanf("%s %s %d", name_for_push, author_for_push, &year_for_push);

        MusicalComposition *element = createMusicalComposition(name_for_push, author_for_push, year_for_push);
        MusicalComposition *current = head;
        while (current->next)
                current = current->next;
        current->next = element;
        element->prev = current;
        element->next = NULL;
}
void pushmanyel(MusicalComposition* head)
{
        int N = 0;
        clear();
        printf("Enter the number of adding elements: ");
        scanf("%d", &N);
        printf("\n");
        int i=0;
        for (i = 0; i < N; i++)
        {
                push(head);
                printf("\n");
        }
        printf("Adding completed successfully!\n\n");
        pause();
}

int count(MusicalComposition*head)
{
        MusicalComposition* current = head;
        int count = 0;
        while (current)
        {
                count++;
                current = current->next;
        }
        return count;
};
void removeEl(MusicalComposition* head, char* name_for_remove, int* CreatedList)
{
        while (head)
        {
                if (strcmp(head->name, name_for_remove) == 0)
                { 
                        if ((head->next == NULL) && (head->prev == NULL))
                        {
                                free(head);
                                head=NULL;
                                printf("\nYou removed the last element in the List\nTo continue use this programm create new List!\n");
                                *CreatedList = 0;
                                return;
                        }

                        else if ((head->prev == NULL) && (head->next))
                        {
                                *head = *head->next;
                                head->prev = NULL;
                                return;
                        }
                        else if ((head->next == NULL) && (head->prev))
                        {
                                head = head->prev;
                                head->next = NULL;
                                return;
                        }
                        else if ((head->next) && (head->prev))
                        {
                                head->next->prev = head->prev;
                                head->prev->next = head->next;
                                return;
                        }
                }
                head = head->next;
        }
}

void sort(MusicalComposition *head)
{
        clear();
        printf("Sort\n\n");
        printf("The original List:\n");
        print_names(head);

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
        printf("\nUpdated List:\n");
        print_names(head);
        printf("\n");
        pause();
}
void removeoddel(MusicalComposition *head)
{
        clear();
        printf("Remove all odd elements\n(numbering starts at zero)\n\n");
        printf("The Original List:\n");
        print_names(head);
        int i = 0;
        MusicalComposition *current = head;
        while (current)
        {
                if (!((++i) % 2))
                        removeEl(head, current->name, 0);
                current = current->next;
        }
        printf("\nUpdated List:\n");
        print_names(head);
        printf("\n");
        pause();
}


void CreatedList()

{
        clear();
        printf("You didn't create List!\nPlease, choose 1 to create List in Menu\n");
        pause();
}


