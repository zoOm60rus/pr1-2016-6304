#include <stdio.h>

int main(void) {
	char s[256];
	scanf("%s", s);
	int i=0;
	while (s[i]!='\0'){
		if (i%2!=0){
			printf("%c", s[i]);
		}
		i++;
	}
	return 0;
}
