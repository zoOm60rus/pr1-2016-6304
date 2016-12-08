nclude<stdlib.h> // заголовочный файл динамического распределения памяти 

void print_sentence(char* arr, int len);// обЪявление функции печати предложения

int main(){
	char c; 
	char* arr=NULL;//присвоение константы нулевого указателя
	int m = 0, n = 0, len = 0, i = 0;
	while ((c = getchar()) != '!')// считываем буфер до "!" 
	{
		switch (c)// сортировка знаков препинания
		{
		case '.':  print_sentence(arr, len); printf("%c\n", c); i = 0; m++; n++; break;
		case ';':  print_sentence(arr, len); printf("%c\n", c); i = 0; m++; n++; break;
		case '?':  i = 0; n++;  break;
		case '\n': i = 0;	break;
		case '\t': i = 0;	break;
		default:// запись остальных элементов
		{
			len = ++i;
			arr = (char*)realloc(arr, i * sizeof(char));// динамическое выделение памяти для каждого элемента
			arr[i - 1] = c; 
		}
		}
	}
	printf("Количество предложений до %d и количество предложений после %d", n, m);// вывод количества предложени до и после
	return 0;
}

void print_sentence(char* arr, int len)// описание функции печати предложения
{	
    for (int i = (arr[0] == ' ') ? 1 : 0; i < len; i++)// проверка на наличие пробела перед предложением
		printf("%c", arr[i]); // печать буфера
}


