#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "locale.h"
#include "struct.h"
#include "createlist.h"
#include "function.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	int decision = 0;
	int createdList = 0;
	MusicalComposition *head = NULL;
	while (decision != 9)
	{
		clear();
		printf("\n  ################################ Menu ###############################\n");
		printf("  #                                                                   #\n");
		printf("  #                                                                   #\n");
		printf("  #   1. Create List                                                  #\n");
		printf("  #   2. Print List                                                   #\n");
		printf("  #   3. Sort List by year ascending                                  #\n");
		printf("  #   4. Add new element                                              #\n");
		printf("  #   5. Add several elements                                         #\n");
		printf("  #   6. Remove elements by search appropriate name                   #\n");
		printf("  #   7. Remove all odd elements                                      #\n");
		printf("  #   8. Number of elements                                           #\n");
		printf("  #   9. Exit                                                         #\n");
		printf("  #                                                                   #\n");
		printf("  #                                                                   #\n");
		printf("  #####################################################################\n\n\n");

		printf("  Choose: ");
		scanf("%d", &decision);

		switch (decision)
		{
		case 1:
			head = add();
			createdList = 1;
			break;
		case 2:
			if (createdList != 1)
				CreatedList();
			else
			{
				clear();
				printf("List:\n");
				print_names(head);
				printf("\n");
				pause();
			}
			break;
		case 3:
			if (createdList != 1)
				CreatedList();
			else
				sort(head);
			break;
		case 4:
			if (createdList != 1)
				CreatedList();
			else
			{
				clear();
				push(head);
				printf("\nAdding elements completed successfully!\n\n");
				pause();
			}
			break;
		case 5:
			if (createdList != 1)
				CreatedList();
			else
				pushmanyel(head);
			break;
		case 6:
			if (createdList != 1)
				CreatedList();
			else
			{
				clear();
				char name_for_remove[80];
				printf("Enter the name to be removed from the List\n");
				scanf("%s", name_for_remove);
				removeEl(head, name_for_remove, &createdList);
				printf("\nRemovig completed successfully!\n\n");
				pause();
			}
			break;
		case 7:
			if (createdList != 1)
				CreatedList();
			else
				removeoddel(head);
			break;
		case 8:
			if (createdList != 1)
				CreatedList();
			else
			{
				clear();
				printf("Number of elements in List: %d\n\n", count(head));
				pause();
			}
			break;
		case 9: break;
		default:
			system("cls");
			printf("There is no such option. Try again!\n\n");
			pause();
		}
	}
	clear();
	return 0;
}
