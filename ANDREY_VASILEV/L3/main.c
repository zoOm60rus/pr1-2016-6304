#include <stdio.h>
#include <stdlib.h>					
#include "text.h"			//Подключаем заголовочный файл с прототипами функций vvod и redact
int main()
{
	char* input=(char*)malloc(10000*sizeof(char));   				//Объявляем переменные и выделяем под них
	int pered, posle, k, i, *index=(int*)malloc(500*sizeof(int));   	        //память
	vvod(input, index, &pered, &posle);                 //Заполняем массив символов и получаем количество предл. до и после
	char* output=(char*)malloc(strlen(input)*sizeof(char));	
	redact(input, index, pered, output);	//Заполняем массив предложений и печатаем результат
	free(input);							//
	free(index);
	free(output);								//Освобождаем выделенную раннее память
	printf("Количество предложений до %d и количество предложений после %d\n", pered, posle);
}



