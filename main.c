#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i=0, m=0, n=0, j=0;
    char *buffer = (char*)malloc(12*sizeof(char));
    while (buffer[i]!='!')
    {
        buffer[i] = getchar();
        //printf("%c", buffer[i]);
        switch (buffer[i])
        {
        case '.':
        {
            while (buffer[0]=='\n'||buffer[0]=='\t'||buffer[0]==' ')
            {
                for (j=0; j<i; j++)
                {
                    buffer[j]=buffer[j+1];
                }
                buffer[i]='\0';
                i--;
            }
            for (j=0; j<=i; j++)
            {
                printf("%c", buffer[j]);
            }
            printf("\n");
            //printf("%s\n", buffer);
            memset(buffer, 0, i);
            i=0;
            m++;
            n++;
            break;
        }
        case ';':
        {
            while (buffer[0]=='\n'||buffer[0]=='\t'||buffer[0]==' ')
            {
                for (j=0; j<i; j++)
                {
                    buffer[j]=buffer[j+1];
                }
                buffer[i]='\0';
                i--;
            }
            for (j=0; j<=i; j++)
            {
                printf("%c", buffer[j]);
            }
            printf("\n");
            //printf("%s\n", buffer);
            memset(buffer, 0, i);
            i=0;
            m++;
            n++;
            break;
        }
        case '?':
        {
            memset(buffer, 0, i);
            i=0;
            m++;
            break;
        }
        case '!':
        {
            printf("Количество предложений до %d и количество предложений после %d", m, n);
            break;
        }
        default:
        {
            i++;
            if (i%10==0)
            {
                buffer = (char*)realloc(buffer, (i+10)*sizeof(char));
            }
            break;
        }
        }
    }
    return 0;
}
