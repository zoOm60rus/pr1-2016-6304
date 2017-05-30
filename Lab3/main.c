#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

char* open_file(char* input_file)
{
	FILE* txt = fopen(input_file, "r");

	if(txt == NULL)
	{
		printf("Fail with openning file");
		return 0;
	}
	fseek(txt,0,SEEK_END);
	int size = ftell(txt);
	if (size == 0)
	{
		printf("File is empty");
		fclose(txt);
		return 0;
	}
	fseek(txt,0,SEEK_SET);

	char* str =(char*)malloc(sizeof(char)*1000);

	fgets(str,size*sizeof(char),txt);
	fclose(txt);
	return str;
}

void list_dir(const char* dir, char** str, int* len)//обход файловой системы
{
	char* current_path = (char*)malloc(sizeof(char)*1000);
	strcpy(current_path,dir);//в строку помещается путь к файлам

	DIR *current_dir = opendir(current_path);//открытие потока каталога
	if(current_dir == NULL)
		return;
        struct dirent* current_file = readdir(current_dir);//считывание структуры с информацией о файле
	
	while(current_file)//пока в дирректории есть файлы
        {
	        int path_len = strlen(current_path);
	        strcat(current_path,"/");
	        strcat(current_path,current_file->d_name);//к строке содержащей путь добавляется имя объекта
	        if(current_file->d_type == DT_REG && strstr(current_file->d_name,".txt")!= NULL)//проверка объекта на файл или дирректорию 
	        {
		        if (((str[*len]) = (char*)open_file(current_path))!= NULL)//возвращается указатель на первую строку из txt файла
		                (*len)++;

		}
		
		if(current_file->d_type == DT_DIR && strcmp(".",current_file->d_name)!=0 && strcmp("..",current_file->d_name)!=0)//если дирректория(кроме родительской и текущей)
			list_dir(current_path, str,len);//рекурсивно вызываем функцию для прочитения этой дирректории
 		current_path[path_len] ='\0';
       		current_file = readdir(current_dir);//считывается следующий объект из данной директории
	}
		
		closedir(current_dir);
}

int compare(const void* a,const void* b)
{
        return atoi(*(char**)a) - atoi(*(char**)b);
}

int main()
{
	char** strings= (char**)malloc(sizeof(char*) * 50);//массив указателей под строки
	int len=0;

	list_dir(".",strings,&len);
	printf("\n\n");
	for(int i=0;i< len;i++)
		printf("%s\n",strings[i]);//вывод неотсортированных строк
	qsort(strings,len,sizeof(char*),compare);//сортировка по возрастанию начальных чисел

        printf("\n\n");
        for(int i=0;i<len;i++)
	        printf("%s\n",strings[i]);//вывод отсортированых строк

	for(int i =0;i<len;i++)//освобождение памяти
		free(strings[i]);
	free(strings);
	return 0;
}






