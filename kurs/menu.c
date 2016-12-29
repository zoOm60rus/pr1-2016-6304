#include "struct.h"
#include "kursfunc.h"
#include "labfunc.h"

void menu ()
{
        int ch, val;
        printf ("Your choice - ");
        fscanf (stdin, "%d", &ch);
        getchar();
        MusicalComposition* song;
        switch (ch)
        {
                case 1:
                        printf ("Amount of songs you want to push - ");
                        scanf ("%d", &val);
                        getchar();
                        for (int i = 0; i < val; i++)
                        {
                                char* name = (char*)malloc(sizeof(char)*80);
                                char* author = (char*)malloc(sizeof(char)*80);
                                int year;
                                printf ("Name - ");
                                fgets (name, 80, stdin);
                                (*strstr(name, "\n"))='\0';
                                printf ("Author - ");
                                fgets (author, 80, stdin);
                                (*strstr(author, "\n"))='\0';
                                printf ("Year - ");
                                fscanf(stdin, "%d", &year);
                                getchar();
                                song = createMusicalComposition (name, author, year);
                        push (song);
                        }
                        break;
                case 2:
                {
                        char* name = (char*)malloc(sizeof(char)*80);
                        printf ("Name of the song you want to remove - ");
                        fgets (name, 80, stdin);
                        (*strstr(name, "\n"))='\0';
                        removeEl (name);
                        break;
                }
                case 3:
                        print_names();
                        break;
                case 4:
                        printf ("%d\n", count(head));
                        break;
                case 5:
                        DeleteS();
                        break;
                case 6:
                  	Sort ();
                        break;
                default:
                        printf ("Incorrect choice\n");
                        break;
        }
}

