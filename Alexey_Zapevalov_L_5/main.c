#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) //Compares two strings using strcmp function
{
    return strcmp((char*) a, (char*) b);
}

int main()
{
    char del[]=". "; //Division tags
    char strn[1000];
    fgets(strn, 1000, stdin);
    char str[30];
    fgets(str, 30, stdin);// Reads text and key word
    int i=0;
    char mas[100][1000];
    char *p=strtok(strn, del); // Divides words from text into strings
    while (p != NULL)
    {
        strcpy(mas[i], p);
        p = strtok (NULL, del);
        i++;
    }
    qsort(mas, i, 1000, compare); // Sorts divided words by ascending

    char* point=(char*)bsearch(str, mas, i, 1000, compare); // Seeks for key word
    if (point==NULL) // Prints result
    {
        printf("doesn't exist");
    }
    else
    {
        printf("exists");
    }
    return 0;
}
