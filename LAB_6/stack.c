#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int *stack; //стэк
int t = 0; //размер стэка

void error () //сообщение об ошибке
{
	printf ("error\n");
	exit (0);
}

void push (int n) //добавить элемент в стэк
{
    stack = (int*)realloc(stack, sizeof(int)*(t+1));
	*(stack+(t++)) = n;
	printf ("ok\n");
}

void pop () //считать элемент из стэка
{
	if (!t)
		error();
	printf ("%d\n", *(stack+(--t)));
}

void top () //получить верхний элемент
{
	if (!t)
		error();
	printf ("%d\n", *(stack+t-1));
}

void size () //получить размер стэка
{
    printf ("%d\n", t);
}

int main ()
{
	stack = (int*)malloc(sizeof(int));
	char* cmds = (char*)malloc(sizeof(char));
	char* cmd = (char*)malloc(sizeof(char));
	do	//считываем последовательность команд
	{
		int i = 0;	
		while ((*(cmd+(i++)) = getchar()) != '\n')
			cmd = (char*)realloc(cmd, sizeof(char)*(i+1));	
		*(cmd+i) = '\0';
		cmds = (char*)realloc(cmds, (strlen(cmds)+strlen(cmd))*sizeof(char)+1);
		strcat(cmds, cmd);
	}while (strcmp(cmd, "exit\n"));
	cmd = strtok (cmds, " \n"); //получаем отдельную команду
	do //вызываем функции, указанные командой или ошибку, если команда не верна
	{
		if (!(strcmp(cmd, "push")))
		{
			cmd = strtok (NULL, " \n");
			for (int i = (*cmd == '-') ? 1 : 0; *(cmd+i) != '\0'; i++)
				if (!isdigit(*(cmd+i)))
					error();
			push(atoi(cmd));
		}
		else if (!(strcmp(cmd, "pop")))
			pop();
		else if (!(strcmp(cmd, "top")))
			top();
		else if (!(strcmp(cmd, "size")))
			size();
		else if (strcmp(cmd, "exit"))
			error();
	}while (cmd = strtok(NULL, " \n"));
	printf ("bye"); //до свидания
	return 0;
}
