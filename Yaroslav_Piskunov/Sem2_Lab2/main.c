/* Yaroslav Piskunov, gr. 6304
Lab Work number 2 - Stack Model */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACKSZ 500 //sets default Size of Stack to 500

int main() {
  int STACKSZ_Ammount = 1; //Multiplier. It controls ammount of memory for stack
  int ElementToPush = 0;
  int size = 0;
  int* stak_massive = (int*)malloc(STACKSZ*sizeof(int));
  char* commandLine = (char*)malloc(100*sizeof(char));
  int commandNumber = 404;
    while(1==1) {
        if (size == STACKSZ*STACKSZ_Ammount){ //check if memory is not enough
         STACKSZ_Ammount++;   
        stak_massive = (int*)realloc(stak_massive, sizeof(int)*STACKSZ*STACKSZ_Ammount);
        } 
        
        fgets(commandLine, 100, stdin);
        if(strchr(commandLine, '\n')) 
        *strchr(commandLine, '\n') = '\0';

      
    //Convreting comands to numerical system
	    if(strcmp(commandLine, "pop") == 0)
            commandNumber = 2;
	    if(strcmp(commandLine, "top") == 0)
            commandNumber = 3;
	    if(strcmp(commandLine, "size") == 0)
            commandNumber = 4;
	    if(strcmp(commandLine, "exit") == 0)
            commandNumber = 5;
        
	//If command was "Push" then we search for it's argument and then convert it into int
        else if (strstr(commandLine, "push ") && strlen(commandLine) >= 6)
	{
		commandLine = commandLine + 5*sizeof(char);
		ElementToPush = atoi(commandLine);
		commandNumber = 1;
    }
                
        
        switch (commandNumber) {
            case 1: //Command "Push"
            stak_massive[size] = ElementToPush;
            printf("ok\n");
            size++;
				break;
            case 2: //Command "Pop"
            if (size!=0){
                printf("%d\n",  stak_massive [size-1]);
                size--; 
            }
            else { 
                printf("error\n");
                return 0; 
            } break;
            case 3: //Command "Top"
            if (size!=0)
               printf("%d\n", stak_massive[size-1]);
            else { 
                printf("error\n");
                return 0; 
            } break;
            case 4: //Command "Size"
            printf("%d\n", size);
            break;
            case 5: // Command "Exit"
            printf("bye\n");
            free(stak_massive);
            return 0;
            break;
            case 404: //In case of any error
            printf("error\n");
                return 0; 
            break;
    }
    }
  return 0;
}
