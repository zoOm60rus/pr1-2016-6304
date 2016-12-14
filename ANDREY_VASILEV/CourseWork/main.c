#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "func.h"

int main(){
    int length, i;
	printf("Количество элементов: ");
    scanf("%d", &length);  
	char memes[70];
    char** names = (char**)malloc(sizeof(char*)*length);
    char** authors = (char**)malloc(sizeof(char*)*length);
    int* years = (int*)malloc(sizeof(int)*length);
    for (i=0;i<length;i++)
    {
		while (getchar() != '\n');
		char name[80];
		char author[80];
		printf("[%d] Название композиции, группа и год: ", i+1);
		scanf("%s %s %d", name, author, &years[i]);
		names[i] = (char*)malloc(strlen(name)*sizeof(char));
		strcpy(names[i], name);	
		authors[i] = (char*)malloc(strlen(author)*sizeof(char));
		strcpy(authors[i], author);
    }
    MusicalComposition* head = createMusicalCompositionList(names, authors, years, length);
	printf("Введенный список: \n");
	print_names(head);
	int k = count(head);
	printf("Кол-во элементов сейчас: %d\n", k);
    char name_for_push[80];
    char author_for_push[80];
    int year_for_push;
    char name_for_remove[80];
	while(getchar() != '\n');
	printf("\nКомпозиция, группа и год для добавления: ");
	scanf("%s %s %d", name_for_push, author_for_push, &year_for_push);
    MusicalComposition* element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);
	push(head, element_for_push);
	printf("Список после дополнения:\n");
	print_names(head);
	k = count(head);
	while(getchar() != '\n');
	printf("Кол-во элементов сейчас: %d\n", k);
	printf("\nКомпозиция для удаления: ");
	scanf("%s", name_for_remove);
    removeEl(head, name_for_remove); 
    k = count(head);
	printf("Список после удаления:\n");
	print_names(head);
	printf("Кол-во элементов сейчас: %d\n", k);
	printf("\n");
	head = AddToBegin(head);
	k = count(head);
	printf("Список после добавления в начало:\n");
	print_names(head);
	printf("Кол-во элементов сейчас: %d\n", k);
	printf("\n");
	head = removeYear(head);
	k = count(head);
	printf("Список поcле удаления нескольких элементов:\n");
	print_names(head);
	printf("Кол-во элементов сейчас: %d\n", k);

    return 0;

}



