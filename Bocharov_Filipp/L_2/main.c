void menu(int ch, int arr[], int n){        
    switch (ch){
        case 0:
        printf("%d", get_max(arr, n));
        break;
        case 1:
        printf("%d", get_min(arr, n));
        break;
        case 2:
        printf("%d", get_sum(arr, n));
        break;
        case 3:
        printf("%d", get_count_first_el(arr, n));
        break;
        default:
        printf("Данные некорректны");
        break;
}
}
int get_max(int arr[], int n){
    int a,max;
    max=arr[0];
    for(a=0;a<n;a++)
    {
    if (arr[a] > max)
        max=arr[a];
    }
    return max;
}

int get_min(int arr[], int n){
     int b,min;
    min=arr[0];
    for(b=0;b<n;b++)
    {
    if (arr[b] < min)
        min=arr[b];
    }
    return min;
}

int get_sum(int arr[], int n){
    int a,summa;
    summa=0;
    for(a=0;a<n;a++)
        if (arr[a]%2==0)
            summa=summa+arr[a];   
    return summa;
}

int get_count_first_el(int arr[], int n){
    int a,eee;
    eee=0;
    for(a=2;a<n;a++)
        if (arr[a]==arr[0])
            eee++;
    return eee;  
    }
