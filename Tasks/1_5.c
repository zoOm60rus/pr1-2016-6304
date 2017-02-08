#include <stdio.h>
#include <stdlib.h>

int getmin(int arr[], int n)
{
 int min=arr[0];
 for(int i=1;i<n;i++)
 {
 if(min>arr[i])
 min=arr[i];
 }
 return min;
}

int getmax(int arr[], int n)
{
 int max=arr[0];
 for(int i=1;i<n;i++)
 {
 if(max<arr[i])
 max=arr[i];
 }
 return max;

}
int main(void) {
	int *arr;
	int size;
	int i=0;
	printf("What size of the array?\n");
	scanf("%d", &size);
	arr=(int*)malloc(size*sizeof(int));
	while (i<size) {
		scanf("%d", &arr[i]);
		i++;
	}
	
	int min, max;
	min=getmin(arr, size);
	max=getmax(arr,size);
	printf("%d", max-min);
	
	return 0;
}
