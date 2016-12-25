#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "abc.h"

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);

void push(MusicalComposition* head, MusicalComposition* element);

void removeEl(MusicalComposition* head, char* name_for_remove);

int count(MusicalComposition* head);

void print_names(MusicalComposition* head);

void push(MusicalComposition* head, MusicalComposition* element){
    while (head->next!=NULL)
        head = head->next;

    head->next = element;
    element->prev = head;
}

int count(MusicalComposition* head){
    int number = 0;
    while (head!=NULL)
    {
        head = head->next;
        number++;
    }
    return number;
}

void print_names(MusicalComposition* head){
    while (head!=NULL)
    {
        printf("%s %s %d\n", head->name, head->author, head->year);
        head = head->next;
    }
}

void removeEl(MusicalComposition* head, char* name_for_remove){
    while (strcmp(head->name, name_for_remove)!=0)
    {
        head = head->next;
    }
    while ((strcmp(name_for_remove, head->name)!=0) && (head!=NULL))
    {
        head = head->next;
    }
    if  ((head->prev!=NULL)&&(head->next!=NULL))
    {
        head->prev->next = head->next;
        head->next->prev = head->prev; free(head);
    }
    else if (head->next == NULL)
    {
        head->prev->next = NULL; free(head);
    }
    else if(head->prev == NULL)
    {
        strcpy(head->name,head->next->name);
                strcpy(head->author, head->next->author);
                head->year = head->next->year;
                head = head->next;
                head->prev->next = head->next;
                head->next->prev = head->prev;
                free(head);



    }
}

int menu () {
int action;
printf("What do you want to do with this list?\n1. Print this List\n2. Add one element\n3. Add some elements\n4. Remove Element\n5. Sort by name\n6. Split and Swap\n0. Nothing. Finish this programm\n...");
scanf("%d", &action);
return action;
}

int main(){
    MusicalComposition* element = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    MusicalComposition* head = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    head = NULL;
    int menu_point, kol, i, y_push, kol_p;
    char a_push[80];
    char n_push[80];

while (1==1){
    if (head == NULL){
    printf("Hello. It's time to make a new list.\nPlease enter a number of units.\n");
    scanf("%d", &kol);
        char** names = (char**)malloc(sizeof(char*)*kol);
    char** authors = (char**)malloc(sizeof(char*)*kol);
    int* years = (int*)malloc(sizeof(int)*kol);
    printf("\nSo, you need to enter some data about composition. It must be the name of the song, it's author name and the year of creation.\n Example: name_of_the_song author's_name year_of_creation\n");
    for(i = 0; i<kol; i++){
        char name[80];
        char author[80];
        scanf ("%s %s %d", name, author, &years[i]);
        names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
        strcpy(names[i], name);
        authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));
        strcpy(authors[i], author);
    }
      head = createMusicalCompositionList(names, authors, years, kol);
            }
            int length = count(head);
            menu_point = menu();
            switch (menu_point) {
        case 1:
            print_names(head);
            break;
        case 2:
            printf("Enter Data For This Element.\n");
            scanf("%s %s %d", n_push, a_push, &y_push);
            element = createMusicalComposition(n_push,a_push, y_push);
            push(head, element);
            break;
        case 3:
            printf("Enter Ammount of Compositions you want to Push.\n");
            scanf("%d", &kol_p);
            for (i = 0; i<kol_p; i++){
                scanf("%s %s %d", n_push, a_push, &y_push);
                element = createMusicalComposition(n_push, a_push, y_push);
                push(head, element);
            }
            break;
        case 4:
            printf("Enter the name of composition you want to remove.\n");
            scanf("%s", n_push);
            removeEl(head, n_push);
            break;
        case 5:
                sort (head, length);
                break;
        case 6:         
            head = split_and_swap (head, length);
            break;
        case 0:
            goto loop;
            break;
        default:
            printf("Error, no such operation.\n");
            break;
            }
}

    loop:
    return 0;

}
