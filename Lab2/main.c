#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flag = -1;//начальная позиция

void push(char ** stack, char * element){ //Положить элемент
    strcpy(stack[++flag],element); //Путём простого копирования
}

void pop(char ** stack){ //Убрать элемент
    flag--;
}

int is_empty(){ //Проверка на пустоту
   return (flag == -1) ? 0 : 1;
}

int main(){
    char c; //Объявление переменной через которую считываем текст
    char tag[15]; //Буфер под теги
    char **stack;
    stack = (char**)malloc(100 * sizeof(char*)); //Выделяем помять под стек, каждый элемент которого - массив
        for (int i = 0; i<100; i++)
                stack[i] = (char*)malloc(15 * sizeof(char)); //Каждый член - тэг
    while (c != '\n' ){ //До тех пор пока не конец строки
        scanf("%c",&c);  //Считываем c
        if (c == '<') { //Если С <
            scanf("%15[^>]",tag); //То начинаем считывать в стэк до > (15 обусловлено тем, что самый длинный тэг 10 символов, но 5 на прозапас)
            if (strcmp(tag,"hr") && strcmp(tag,"br")){ //Если это не br или hr
                if (tag[0] != '/') //Если последний тег не закрывающий
                    push(stack,tag);  // Кладём в стэк       
                else{ //Иначе
                    if (is_empty() == 0){ // Если стек пуст
                        printf("wrong"); //То ошибка
                        return 0; //Выходим
                    }
                    else{ //Иначе
                        if (strcmp(stack[flag],tag+1)){//если закрывающий отличен от нынешнего
                            printf("wrong");
                            return 0;
                        }
                        else
                            pop(stack);  
                    }
                }
            }
        }                                       
    }
    if (!is_empty()) //Конечное условие проверки
        printf("correct");//Если путо, то все тэги закрыты
    else
        printf("wrong");//А если нет, то не все
}