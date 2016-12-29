#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
MusicalComposition* createMusicalComposition(char* name, char* author, int year){
	MusicalComposition* head = (MusicalComposition*)malloc(sizeof(MusicalComposition));
	strcpy(head->name, name);
	strcpy(head->author, author);
	head->year = year;
	head->prior=NULL;
	head->next=NULL;
	return head;
}
//создание списка
MusicalComposition* createMusicalCompositionList(char** array_names,char** array_authors, int* array_years, int n){
	MusicalComposition* tmp = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
	MusicalComposition* head = tmp;
	int i;
	for (i=1; i<n; i++){
		tmp->next = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
		tmp->next->prior = tmp;
		tmp = tmp->next;
	}
	return head;
}
//вставка элемента в конец списка
void push(MusicalComposition* head, MusicalComposition* element){
	while(head->next){
	head=head->next;
	}
	head->next=element;
	element->prior=head;
}
////удаление определенного элемента
void removeEl(MusicalComposition* head, char* name_for_remove){
	MusicalComposition *tmp = head;
	while (tmp->next){
		if (strcmp(tmp->name, name_for_remove) == 0) {
			if ((tmp->prior) == NULL){
				MusicalComposition *ntmp = tmp->next;
				strcpy(tmp->name, ntmp->name);
				strcpy(tmp->author, ntmp->author);
				tmp->year = ntmp->year;
				ntmp->next->prior = tmp;
				tmp->next = ntmp->next;
				free(ntmp);
			}
			else{
				tmp->prior->next = tmp->next;
				tmp->next->prior = tmp->prior;
				free(tmp);
			}
		}
		tmp = tmp->next;
	}
	if ((strcmp(tmp->name, name_for_remove) == 0) && (tmp->next == NULL)){
		tmp->prior->next = NULL;
		free(tmp);
	}

}
//кол-во элементов
int count(MusicalComposition* head){
	int count=0;
	while (head){
		count++;
		head=head->next;
		}
	return count;
}
//вывод имен
void print_names(MusicalComposition* head){
	MusicalComposition *tmp = head;
	while (tmp->next){
		printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
	printf("%s\n", tmp->name);
}
//вывод списка
void print_list(MusicalComposition* head){
        while (head->next){
                printf("%s ", head->name);
		printf("%s ", head->author);
		printf("%d\n", head->year);
                head = head->next;
        }
        printf("%s ", head->name);
        printf("%s ", head->author);
        printf("%d\n", head->year);
}
