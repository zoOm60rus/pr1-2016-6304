#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct MusicalComposition// Описание структуры MusicalComposition
{
    char name[80];
    char author[80];
    int year;
    struct MusicalComposition *next;
    struct MusicalComposition *prev;
};
typedef struct MusicalComposition MusicalComposition;//присваивание структкре имя MusicalComposition
MusicalComposition* createMusicalComposition(char *name, char *author, int year);//создание музыкальной композиции
MusicalComposition *createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);//создание плейлиста
void push(MusicalComposition* head, MusicalComposition* element);//добавить в плейлист композицию
void removeEl(MusicalComposition* head, char*name_for_remove);//удаление имени композиции
int count(MusicalComposition *head);//подсчёт количества композиций в плейлисте
void print_names(MusicalComposition *head);//вывод названий композиций
void function(MusicalComposition *head);//функция, которая вставляет в середину списка 3 элемента
void change(MusicalComposition *head);//функция замены строчных букв в названии прописными






