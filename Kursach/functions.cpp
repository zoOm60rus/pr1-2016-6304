#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
struct MusicalComposition
{
    char name[80];
    char author[80];
    int year;
    struct MusicalComposition *next;
    struct MusicalComposition *prev;
};

typedef struct MusicalComposition MusicalComposition;

MusicalComposition* createMusicalComposition(char *name, char *author, int year)
{
    MusicalComposition* Composition= (MusicalComposition*)malloc(sizeof(MusicalComposition));
    strcpy(Composition->name,name);
    strcpy(Composition->author,author);
    Composition->year = year;
    Composition->next = NULL;
    Composition->prev = NULL;
    return Composition;
}
MusicalComposition *createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
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
        head = head-> next;
        head->next = element;
        element->prev = head;
        element->next = NULL;
}

void removeEl(MusicalComposition* head, char*name_for_remove)
{
        while (head)
        {
                if (strcmp(head->name, name_for_remove) == 0)
                {
                        if (head->next == NULL)
                        {
                        head->prev->next = NULL;
                                return;
                        }
                        else if (head->prev == NULL)
                        {
                                head->next->prev = NULL;
                                return;
                        }

                        head->prev->next = head->next;
                        head->next->prev = head->prev;

                        break;
                }

                head = head->next;
        }

}

int count(MusicalComposition *head)
{
        int count = 0;
        while (head)
        {
                count++;
                head = head->next;
        }
        return count;
};

void print_names(MusicalComposition *head)
{
        while (head)
        {
                printf("%s\n", head->name);
                head = head->next;
        }
}

void function(MusicalComposition *head)//функция, которая вставляет в середину списка 3 элемента
{
        int p=count(head)/2;//находим середину списка
MusicalComposition* sr1 =head;//буфер1
MusicalComposition* sr2;//буфер2
MusicalComposition* nw1=(MusicalComposition*)malloc(sizeof(MusicalComposition));//выделение памяти под три новых узла
MusicalComposition* nw2=(MusicalComposition*)malloc(sizeof(MusicalComposition));
MusicalComposition* nw3=(MusicalComposition*)malloc(sizeof(MusicalComposition));

for(int i=0;i<p;i++)//цикл обхода списка до середины
{
sr1=sr1->next;//указатель на первое место разрыва(справа) 
}
sr2=sr1->prev;//указатель на первое место(слева)
scanf("%s/n",nw1->name);//ввод данных
scanf("%s/n",nw1->author);
scanf("%d/n",&nw1->year);
scanf("%s/n",nw2->name);
scanf("%s/n",nw2->author);
scanf("%d/n",&nw2->year);
scanf("%s/n",nw3->name);
scanf("%s/n",nw3->author);
scanf("%d/n",&nw3->year);

sr2->next=nw1;//соединение узлов с остальным списком
nw1->next=nw2;
nw1->prev=sr2;
nw2->prev=nw1;
nw2->next=nw3;
nw3->prev=nw2;
nw3->next=sr1;
sr1->prev=nw3;

}

void change(MusicalComposition *head)//функция замены строчных букв в названии прописными
{
        MusicalComposition* ch = head;
        char str[80];//buffer
        int len;
        int q ='A'-'a';//расстояние в таблице ASCII между заглавной и прописной буквами
        while(ch)//цикл обхода списка
        {
                strcpy(str,ch->name);//копируем имя в буфер
                len = strlen(ch->name);//определяем длину имени
                for(int j=0;j<len; j++)//цикл обхода символов имени
                {
                        if ((str[j]>=97)&&(str[j]<=122))//проверка на то, что явл. ли символ строчной буквой
                        {
                                str[j]=str[j]+q;//меняем символ на прописной
                        }

	        }
                strcpy(ch->name,str);//копируем буфер в имя
                ch = ch->next;//перемещаемся в следующий узел
	}
}


