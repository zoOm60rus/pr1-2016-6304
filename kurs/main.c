#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "labfunc.h"

void menu();
MusicalComposition* head = NULL;

int main ()
{
        char c = 'y';
        int val;
        printf ("Creating Musical composition list\nAmount of compositions - ");
        scanf("%d", &val);
        getchar(); 
        char** names = (char**)malloc(sizeof(char*)*val);
        char** authors = (char**)malloc(sizeof(char*)*val);
        int* years = (int*)malloc(sizeof(int)*val);
        int year, ch;
        char name[80];
        char author[80];
        for (int i=0;i<val;i++)
        {
                printf ("Name - ");
                fgets(name, 80, stdin);
                printf ("Author - "); 
                fgets(author, 80, stdin);
                printf ("Year - ");
                fscanf(stdin, "%d", &years[i]);

                (*strstr(name,"\n"))='\0';
                (*strstr(author,"\n"))='\0';

                names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
                authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));

                strcpy(names[i], name);
                strcpy(authors[i], author);
                getchar();
        }
        head = createMusicalCompositionList(names, authors, years, val);
        printf ("Menu:\n1 - Push elements\n2 - remove element\n3 - Print names\n4 - Amount of compositions\n");
	printf ("5 - Delete authors with \"S\" or \"s\"\n");
	printf ("6 - Sort by alphabet\n");
        while (c == 'y')
        {
                menu();
                printf ("Want to continue? (y/n)");
                scanf ("%c", &c);
        }
        return 0;
}
