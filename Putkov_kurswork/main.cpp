#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functionsFromLab.h"
#include "kursFunctions.h"

//struct MusicalComposition {
//	char name[80];
//	char author[80];
//	int year;
//	struct MusicalComposition* next;
//	struct MusicalComposition* prev;
//
//};

int main()
{

	int length;

	printf("Enter the length of the Musical list\n");

	scanf("%d", &length);



	int tmp;

	while((tmp = getchar()) != '\n');



	char **names = (char**)malloc(sizeof(char*)*length);

	char **authors = (char**)malloc(sizeof(char*)*length);

	int *years = (int*)malloc(sizeof(int)*length);

	printf("Enter the composition's name, author and year of origin:\n");

	for (int i = 0; i < length; ++i)

	{

		char name[80];

		char author[80];

		fgets(name, 80, stdin);

		fgets(author, 80, stdin);

		fscanf(stdin, "%d", &years[i]);

		while((tmp = getchar()) != '\n');

		printf("Enter the composition's name, author and year of origin:\n");

		(*strstr(name, "\n")) = 0;

		(*strstr(author, "\n")) = 0;



		names[i] = (char*)malloc(sizeof(char*)*(strlen(name) + 1));



		authors[i] = (char*)malloc(sizeof(char*)*(strlen(author) + 1));



		strcpy(names[i], name);

		strcpy(authors[i], author);

	}



	MusicalComposition *head = createMusicalCompositionList(names, authors, years, length);

	MusicalComposition *ptr=head;

	int action=0;

	int elements=0;

	int choise=2;

	int k;



	while (choise!=1)

	{

		printf("What actions are you want to do with the list:\n 1.Add an element\n 2.Remove an elements\n 3.Change the list regarding the number you will write\n 4.Change the list by the parties\n 5.Print the list\n");

		scanf("%d", &action);

		int tmp;

	    while((tmp = getchar()) != '\n');

		switch (action)

		{

		case 1:

			{

			char name_for_push[80];
			char author_for_push[80];									   int year_for_push;
			 
			printf("Enter the composition's name, author and year of origin:\n");
			fgets(name_for_push, 80, stdin);
			fgets(author_for_push, 80, stdin);
			fscanf(stdin, "%d", &year_for_push);
			
			while((tmp = getchar()) != '\n');
			
			(*strstr(name_for_push, "\n")) = 0; 

			(*strstr(author_for_push, "\n")) = 0;



			MusicalComposition *element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);
			push(head, element_for_push);
			k=count(head);
			break;
			}

		case 2:
			{

			char name_for_remove[80];
			printf("Enter the name of composition which you want to remove:\n");

			fgets(name_for_remove, 80, stdin);

			(*strstr(name_for_remove, "\n")) = 0;

			removeEl(head, name_for_remove);
			k=count(head);
			break;
			}

		case 3:
			{

			int n;
			printf("Choose the number which the list will be changed regarding\n");
			fscanf(stdin, "%d", &n);
			PermutationRegarding_n(ptr, n);
			break;
			}

		case 4:
			{

			k=count(head);
			head=PermutationRegardingMiddle(head, k);
			break;
			}

		case 5:
			{

			k=count(head);
			print_names(head);
			printf("The amount of musical composition is %d\n", k);
			break;
			}
		}

		printf("Are you want to exit?\n 1.Yes\n 2.No\n"); 
		fscanf(stdin, "%d", &choise);
	}
	return 0;
}
