#include <stdio.h>


int main(void) {
	// your code goes here
	char s[256];
	char c;
	int i=0;
	int rep=0;
	scanf("%s\n", s);
//	printf("%s", s);
	scanf("%c", &c);
	while (s[i]!='\0'){
		if (s[i]!=c) {
			printf("%c", s[i]);
			}
					
		i++;
	}
	return 0;
}