#include <stdio.h> 
#include <stdlib.h> 

void sentence_to_print(char* arr, int len, int sen); 

int main() { 
char c; 
int m = 0; 
int n = 0; 
int sen=0;
char *arr=(char*)malloc(1000*sizeof(char)); 
int i; 
int len = 0; 
while ((c = getchar()) != '!'){ 
if ((c == ';') || (c == '.')){ 
arr[len++] = c; 
sentence_to_print(arr, len, sen); 
sen=1;
n++; 
m++; 
len = 0; 
} 
if (c == '?'){ 
len = 0; 
n++; 
} 
if ((c == '\t') || (c == '\n')){ 
len = 0; 
} 
else 
arr[len++] = c; 

} 
printf("\n");
printf("Количество предложений до %d и количество предложений после %d", n, m); 
return 0; 

} 
void sentence_to_print(char* arr, int len, int sen){ 
int i, k; 
if (sen!=0)
printf("\n");
if(arr[0] =='?') 
k = 2; 
else 
k = 0; 
if ((arr[0]==';') || (arr[0]=='.'))
    k+=2;

for (i=k; i<len; i++){
if (arr[i] == '?') 
continue;
printf("%c", arr[i]); 
} 
}
