#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Описание структуры MusicalComposition
typedef struct MusicalComposition {
    char* name;
    char* author;
    int year;
    struct MusicalComposition *next;
    struct MusicalComposition *prev;
} MusicalComposition;

// Создание структуры MusicalComposition

MusicalComposition* createMusicalComposition(char* name, char* author, int year) {
    MusicalComposition* song = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    song -> name = name;
    song -> author = author;
    song -> year = year;
    song -> next = NULL;
    song -> prev = NULL;
    return song;
}

// Функции для работы со списком MusicalComposition

MusicalComposition *createMusicalCompositionList(char **array_names, char **array_authors, int *array_years, int n) {
    MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
    MusicalComposition *prev = head;
    MusicalComposition *current;

    for (int i = 1; i < n; i++) {
        current = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
        current -> prev = prev;
        prev -> next = current;
        prev = current;
    }
    return head;
}


void push(MusicalComposition* head, MusicalComposition* element) {
    MusicalComposition *tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    tmp = head;
    while (tmp -> next != NULL) {
        tmp = tmp -> next;
    }
    tmp -> next = element;
    element -> prev = tmp;
}


void removeEl(MusicalComposition* head, char* name_for_remove) {
    MusicalComposition *tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    tmp = head;
    while (strcmp(tmp -> name, name_for_remove)) {
        tmp = tmp -> next;
    }
    if (tmp -> prev == NULL) {
        tmp = tmp -> next;
        tmp -> prev = NULL;
        *head = *tmp;
        }   
        else if (tmp -> next == NULL) {
                tmp = tmp -> prev;
                tmp -> next = NULL;
            } else {
            tmp -> prev -> next = tmp -> next;
            tmp -> next -> prev = tmp -> prev;
        }
}


int count(MusicalComposition* head) {
    MusicalComposition *tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    tmp = head;
    int count = 1;
    while (tmp -> next != NULL) {
        tmp = tmp -> next;
        count++;
    }
    return count;
}


void print_names(MusicalComposition * head) {
    MusicalComposition *tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    tmp = head;
    while (tmp -> next != NULL) {
        printf("%s\n", tmp -> name);
        tmp = tmp -> next;
    }
    printf("%s\n", tmp -> name);
}


 void removeUnevenEls(MusicalComposition* head) {
    MusicalComposition *tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    tmp = head;
    int count = 1;
    while (tmp != NULL) {
        if (!((count % 2) == 0)) {
            if (tmp -> prev == NULL) {
                tmp = tmp -> next;
                tmp -> prev = NULL;
                *head = *tmp;
            }
            else if (tmp -> next == NULL) {
                tmp = tmp -> prev;
                tmp -> next = NULL;
            } else {
                tmp -> prev -> next = tmp -> next;
                tmp -> next -> prev = tmp -> prev;
            }
        }
        tmp = tmp -> next;
        count++;
    }
}

 void sortirovka(MusicalComposition *head) 
{ 
	int i=count(head);
	int k=0;
	MusicalComposition *curr; // Создаём дополнительный указатель, для перемещения по списку 
	while (k<i){
		while(head->prev)
			head=head->prev;
		
	while (head->next) //Перемещаемся до конца списка 
	{ 
		curr = head;
		while (curr->next) //опять же перемещаемся до конца 
		{ 
			if (strcmp(curr->author,curr->next->author)>0) //Если авор больше то свапает 
				{ 

					MusicalComposition *tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition)); //Выделяем память для доп. переменной 
					strcpy(tmp->name, curr->next->name); strcpy(tmp->author, curr->next->author); tmp->year = curr->next->year; //функция 
					strcpy(curr->next->name, curr->name); strcpy(curr->next->author, curr->author); curr->next->year = curr->year; //для 
					strcpy(curr->name, tmp->name); strcpy(curr->author, tmp->author); curr->year = tmp->year; //свапа 

					free(tmp);//освобождаем память 
				} 
			curr = curr->next; //продвигаемся 
		} 
		head = head->next; //продвигаемся 
	} 
k++;}
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
    int length; int a = 1,year;
    printf("Количество композиций в списке: ");
    scanf("%d", &length);
    char** names = (char**)malloc(sizeof(char*)*length);
    char** authors = (char**)malloc(sizeof(char*)*length);
    int* years = (int*)malloc(sizeof(int)*length);
    int i,t;
    char name[80];
    char author[80];
    for (i=0;i<length;i++)
    {
        printf("%d) Введите название, автора и год : ", i+1); 
        scanf("%s %s %d", name, author, &year);
        printf("-----------------------------------------\n");
        names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
        authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));
        strcpy(names[i], name);
        strcpy(authors[i], author);

    }
    MusicalComposition* head = createMusicalCompositionList(names, authors, years, length);
    while (a!=0){

        printf("Выберите действие: \n");
        printf("0. Выйти\n1. Добавить 1 элемент\n2. Добавить несколько элементов \n3. Удалить\n4. Список\n5. Количество элементов\n6.Удалить нечётные\n7.Просортировать по возрастанию авторов\n");
        scanf("%d", &a);
         printf("-----------------------------------------\n");
        switch (a){
            case 0: break;
            case 1:
                printf("Введите имя, автора и год: "); //просим ввести название, автора и год написания композиции
                scanf("%s %s %d", name, author, &year);//записываем значения
                push(head, createMusicalComposition(name, author, year));//обращаемся к функции push
                break;
            case 2:
            	printf("Количество композиций на добавление\n");
            	scanf("%d", &t);//записываем количество композиций для добавления
            	for(i=0;i<t;i++){
            	printf("Введите имя, автора и год: ");//просим ввести название, автора и год написания композиции
                scanf("%s %s %d", name, author, &year);//записываем значения
                push(head, createMusicalComposition(name, author, year));//обращаемся к функции push
            	}
            	break;
            case 3:
                printf("Введите название: ");
                scanf("%s", name);
                removeEl(head, name);
                break;
            case 4:
                print_names(head); 
                break;
			case 5:
				printf("Количество композиций в списке %d\n", count(head));
				break;
			case 6:
				removeUnevenEls(head);
                break;
            case 7:
            	sortirovka(head);
            	break;
            default: printf("Дейсвия не существует"); break;
        }
         printf("-----------------------------------------\n");
    }
    return 0;

}