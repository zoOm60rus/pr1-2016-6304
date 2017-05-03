#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 600
typedef struct num{
    int a;
    struct num *next;
    struct num *prev;
}num;

num* stackInit(num* stack){ //Initializing stack
    stack = (num*)malloc(sizeof(num));
    stack->prev = NULL;
    return stack;
}

num* push(num* stack, int a){ //Pushing element to the stack
    stack->a = a;
    stack->next = (num*)malloc(sizeof(num));
    stack->next->prev=stack;
    stack = stack->next;
    stack->next = NULL;
    return stack;
}

int getLastTwo(num* stack, int *a, int *b){ //Getting last two elements
    if (stack!=NULL){ //Even if stack == NULL, if still calls stack->prev, and program crashes
        if (stack->prev!=NULL){
            *a=stack->prev->a;
            if (stack->prev->prev!=NULL){
                *b=stack->prev->prev->a;
            }
            else
                return 0;
        }
        else
            return 0;
    }
    else
        return 0;
    return 1;

}

num* Replace(num*stack, int a){ //Replacing previous element (technically - pre-previous, but current is empty)
    if (stack!=NULL){ //with given one and deleting current
        if (stack->prev!=NULL){
            if (stack->prev->prev!=NULL){
                stack->prev->prev->a = a;
                stack=stack->prev;
                stack->next = NULL;
            }
        }
    }
    return stack;
}


int main()
{
    int a; int b; int err = 1;
    char* str = (char*)malloc(N*sizeof(char));
    fgets(str, N, stdin); //Input. I couldn't figure out the ending symbol of input, so fgets instead of getchar cycle
    num* stack = NULL;
    char *s = strtok(str, " ");
    while ((s!=NULL) && (err == 1)){ //There is no point of going through the cycle if an error was found
        switch (s[0]){
            case '+':
                err = getLastTwo(stack, &a, &b);
                stack = Replace(stack, a+b);
                break;
            case '*':
                err = getLastTwo(stack, &a, &b);
                stack = Replace(stack, a*b);
                break;
            case '/':
                err = getLastTwo(stack, &a, &b);
                stack = Replace(stack, b/a);
                break;
            default:
                if ((s[0]=='-') && (s[1] == '\0')){ //Both "-" and negative number start with '-'
                    err = getLastTwo(stack, &a, &b); //So i check this case separately
                    stack = Replace(stack, b-a);
                }
                else{
                    if (stack == NULL) //If there were no pushes, init stack.
                        stack = stackInit(stack); //It's easier to understand that way if there were no "oush" calls.
                    stack = push(stack, atoi(s));
                }
                break;
        }
        s = strtok(NULL, " ");
    }
    if ((err == 0) || (stack->prev->prev!=NULL)) //Checking also if there is more than one element in stack
        printf("error\n");
    else
        printf("%d", stack->prev->a);
    return 0;
}
