#include<string.h>
#include <stdlib.h>

#include "struct.h"			//Подключаем файл с объявлением структуры

MusicalComposition* createMusicalComposition(char* name, char* author, int year) 
{    
    MusicalComposition* tmp=NULL;									//Создаем указатель на структуру.
	tmp =(MusicalComposition*)malloc(sizeof(MusicalComposition));	//Выделяем под структуру память.
    strcpy(tmp->name, name);								//Скопируем переданные в функцию
    strcpy(tmp->author, author);							//значения в поля созданной структуры
    tmp->year = year;													
    return tmp;	   		//Возвращаем указатель на структуру
}





