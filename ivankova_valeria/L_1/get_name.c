#include <stdio.h>
#include <string.h>
int puts(const char *str);
char * strncat( char * destptr, char * srcptr, size_t num );
char* get_name(){
char* name = (char*)malloc(80*sizeof(char));
int i = 0;
char ch;
while ((ch = getchar()) != '\n')
    {
      name[i] = ch;
      i++;
    }
    name[i] = '\0';
    return name;
} 
	 
