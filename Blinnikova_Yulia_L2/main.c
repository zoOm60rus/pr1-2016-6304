#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void push(int* stack, int symbol, int* i)
{
	stack[*i+1] = symbol;
    (*i)++;
}

int pop(int* i, int* stack)
{
	int cur = stack[*i];
	(*i)--;
	return cur;
}


int main()
{
	char* str = (char*)malloc(sizeof(char) * 100);
    fgets(str,100,stdin);
	int count = -1;
    int stack[100];
	char*ptr = strtok(str, " ");
    while(ptr)
    {
        int symbol = atoi(ptr);
        if (symbol != 0)
			push(stack, symbol, &count);
		else
		{
			if (count < 1)
			{
				printf("error");
				return 0;
			}
			int y = pop(&count, stack);
			int x = pop(&count, stack);

			switch (ptr[0])
			{
			case '+':
				push(stack, x + y, &count);
				break;
			case'-':
				push(stack, x - y, &count);
				break;
			case '*':
				push(stack, x * y, &count);
				break;
			case '/':
				push(stack, x / y, &count);
				break;
			default:
			{
				printf("error");
				return 0;
			}
			}
		}
        ptr = strtok(NULL, " ");
	}
	int result = pop(&count, stack);
	if (count > -1)
	{
		printf("error");
		return 0;
	}
	else
		printf("%d", result);
	return 0;

}
