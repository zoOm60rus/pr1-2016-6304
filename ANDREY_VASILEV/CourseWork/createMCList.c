#include <stdlib.h>

#include "struct.h" //Подключаем заголовочный файл с объявлением структуры
#include "func.h"	//и файл с прототипом функции "createMusicalComposition"

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
	MusicalComposition* hold = NULL; //Создаем указатели на вспомогательные структуры и 
	MusicalComposition* temp = NULL; //присваиваем им нулевые указатели
	MusicalComposition* start=NULL;
	start = createMusicalComposition(array_names[0], array_authors[0], array_years[0]); //Создаем первый элемент списка
    hold = start;									//и присваиваем значение "start" временной переменной, чтобы вернуть
	int i;											//значение в конце
	start->prev = NULL;
    for (i = 1; i<=n; i++)			//Цикл начинается с единицы и выполняется, пока счетчик "i" не будет равен количеству
    {								//элементов. При условии, когда счетчик меньше "n" - присваиваем временной переменной
        if(i<n){					//"temp" текущее значение. Далее создаем следующий элемент и делаем его текущим.
        	temp = start;			//Теперь элемент "temp" является предыдущим для текущего элемента "start"
        	start->next = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
        	start = start->next;
        	start->prev = temp; 
        } else start->next = NULL; //При достижении последнего элемента присваиваем след. элементу нулевой указатеь
    }
    start = hold;  	//Возвращаем "start" исходное значение, сохраненное в строке 22. 
    return start;
}


