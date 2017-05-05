#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Program reads strings with commands and works with array
//Array fills and cleans like stack
int main()
{
    int i=0, c=1, n, j=0, flag=0;   // c - input strings counter, n - result strings amount counter
    char del[]="\n ";               // i - strtok counter, j - result counter
    char vvod[200][20];             // del - dividing symbols array, vvod - input array
    char mas[200][20];              // mas - in-between result counter
    int array[200];                 // array - result counter
    vvod[0][0]='0';                 //checking previous result needs array to begin with 1
    while(strcmp(vvod[c-1], "exit\n")!=0)   //reading strings
    {
            fgets(vvod[c], 20, stdin);
            //printf("%s\n", vvod[c]);
            c++;
    }
    for (n=1; n<c; n++)
    {
    char *p=strtok(vvod[n], del); // Divides words from input strings
    while (p != NULL)
    {
        strcpy(mas[i], p);
        p = strtok (NULL, del);
        i++;
    }
    }
    for (n=0; n<i; n++) //works with array depending on commands
    {
        if (flag==0)
        {
            if (strcmp(mas[n], "push")==0) // pushes number into array
            {
                n++;
                array[j]=atoi(mas[n]);
                printf("ok\n");
                j++;
            }
            else if (strcmp(mas[n], "size")==0) // prints size of occupied cells
            {
                printf("%d\n", j);
            }
            else if (strcmp(mas[n], "exit")==0) // ends program by breaking cycle
            {
                printf("bye\n");
                flag=1;
            }
            else if (j!=0)
            {
                if (strcmp(mas[n], "pop")==0) //prints top element and reduces result array counter
                {
                    printf("%d\n", array[j-1]);
                    j--;
                }
                else if (strcmp(mas[n], "top")==0) // prints top element
                {
                    printf("%d\n", array[j-1]);
                }
            }
            else
            {
                printf("error\n"); // default action
                flag=1;
            }
        }
    }
    return 0;
}
