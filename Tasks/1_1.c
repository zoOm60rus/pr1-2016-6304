#include <stdio.h>

void pows(int a,int n) {
	int result=1;
	if (a==1) {
		printf("%d", 1);
	}
	else if (n==1) {
		printf("%d", a);
	}
	else if (n==0){
		printf("%d", 1);
	}
	else {
		result=1;
		for (int i=0;i<n;i++) {
			result*=a;
		}
		printf("%d", result);
	}
}

int main(void) {
	int a,b;
	scanf("%d %d", &a, &b);
	pows(a,b);
	return 0;
}
