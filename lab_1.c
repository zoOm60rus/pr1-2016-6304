#include <stdio.h>
#include <stdlib.h>

typedef struct scob
{
    char t;
    struct scob* sec;
    struct scob* first;
} scob;

int main()
{
    int tru=1;
    int i;
    char a;
    char ch;
    scob* sc=(scob*)malloc(sizeof(scob));
    sc->sec=NULL;
    while(ch!='\n')
    {
        ch=getchar();
switch(ch){
case '(':
sc->t=')';
sc->sec=(scob*)malloc(sizeof(scob));
sc->sec->first=sc;
sc=sc->sec;
tru=1;

case '<':
sc->t='>';
sc->sec=(scob*)malloc(sizeof(scob));
sc->sec->first=sc;
sc=sc->sec;
tru=1;

case '{':
sc->t='}';
sc->sec=(scob*)malloc(sizeof(scob));
sc->sec->first=sc;
sc=sc->sec;
tru=1;

case '[':
sc->t=']';
sc->sec=(scob*)malloc(sizeof(scob));
sc->sec->first=sc;
sc=sc->sec;
tru=1;
default tru=0;
        }
        /*if (ch=='(')
        {
            sc->t=')';
            sc->sec=(scob*)malloc(sizeof(scob));
            sc->sec->first=sc;
            sc=sc->sec;
            tru=1;
        }
        else if (ch=='<')
        {
            sc->t='>';
            sc->sec=(scob*)malloc(sizeof(scob));
            sc->sec->first=sc;
            sc=sc->sec;
            tru=1;
        }
        else if (ch=='{')
        {
            sc->t='}';
            sc->sec=(scob*)malloc(sizeof(scob));
            sc->sec->first=sc;
            sc=sc->sec;
            tru=1;
        }
        else if (ch=='[')
        {
            sc->t=']';
            sc->sec=(scob*)malloc(sizeof(scob));
            sc->sec->first=sc;
            sc=sc->sec;
            tru=1;
        }
        else
            tru=0;
    }*/

    if ((ch =='>') || (ch == '}') || (ch == ')') || (ch == ']'))
    {
        if (sc->first!=NULL)
        {
            tru=0;
        }
      else
       if(sc->first->t=a){
      sc=sc->first;
       }
    }}
    if (tru == 1)
    {
        printf("correct");
    }
    else
        printf("wrong");
    return 0;
}


