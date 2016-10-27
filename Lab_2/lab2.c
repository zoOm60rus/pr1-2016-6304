nclude <stdio.h> 
#include <stdlib.h> 

int get_max(int arr[], int n){ 
    int i; 
    int max; 
    max=arr[0]; 
    for (i=0; i<n; ++i){ 
        if(arr[i]>max) 
    max=arr[i]; 
    } 
    return max; 
} 
int get_min(int arr[], int n){ 
    int i; 
    int min; 
    min=arr[0]; 
    for (i=0; i<n; ++i) { 
        if(arr[i]<min) 
        min=arr[i]; 
    } 
    return min; 
} 
int get_sum(int arr[], int n){ 
    int i; 
    int summ=0; 
    for (i=0; i<n; ++i){ 
         if (arr[i]%2==0) 
        summ+=arr[i]; 
    } 
    return summ; 
} 
int get_count_first_el(int arr[], int n){ 
    int i; 
    int c=0; 
    for (i=1; i<n; ++i){ 
        if(arr[i]==arr[0]) 
        ++c; 
    } 
    return c; 
}
void menu(int ch, int arr[], int n){ 
switch ( ch ) { 
    case 0: 
        printf("%d\n", get_max(arr, n)); 
        return; 
    case 1: 
        printf("%d\n", get_min(arr, n)); 
        return; 
    case 2: 
        printf("%d\n", get_sum(arr, n)); 
        return; 
    case 3: 
        printf("%d\n", get_count_first_el(arr, n)); 
        return; 
    default: 
        printf("Данные некорректны"); 
        return; 
        } 
} 
