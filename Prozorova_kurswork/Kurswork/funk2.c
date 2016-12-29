#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "funk.h"

MusicalComposition* pushfirst(MusicalComposition* head, MusicalComposition* element) {
head->prior = element;
element->next = head;
return element;
}
MusicalComposition* ChangeList(MusicalComposition* head){
	MusicalComposition* current = head;
	int l = count(head);
	int i;
	float n;
	if (l%2==0) n=l/2;
	else n=l/2+0.5;
	for (i=0; i<n; i++){
		MusicalComposition* tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
		strcpy(tmp->name, head->name);
		strcpy(tmp->author, head->author);
		tmp->year = head->year;
		current=pushfirst(current, tmp);
		head=head->next;
	}
	print_list(current);
	return current;
}

//поменять местами элементы
void exchange(MusicalComposition* a, MusicalComposition* b){
	char rubbish[80];
	int rubb;
	strcpy(rubbish, a->name);
	strcpy(a->name, b->name);
	strcpy (b->name, rubbish);
	strcpy(rubbish, a->author);
	strcpy(a->author, b->author);
	strcpy (b->author, rubbish);
	rubb=a->year;
	a->year=b->year;
	b->year=rubb;
}
//разбить список на группы и поменять в нем начальный и конечный элементы местами
MusicalComposition* ChangeList1(MusicalComposition* head, int m){
	int i=0; 
	int j=0;
	int n=count(head);
	MusicalComposition** arr = (MusicalComposition**)malloc((n+1)*sizeof(MusicalComposition*));
        for (i = 0; i<n; i++) arr[i] = (MusicalComposition*)malloc(sizeof(MusicalComposition*));
        for (i = 0; i<n; i++){
        	arr[i] = head;
        	head = head->next;
        }
	if (n%m==0){
        	for(i = 0; i<n-1; i = i + m){
        		arr[i+m-1]->next = NULL;
        		arr[i]->prior = NULL;
        		exchange(arr[i], arr[i+m-1]);
        	}
        	for (i = 1; i<n-1; i = i + m){
        		arr[i+m-2]->next = arr[i+m-1];
        		arr[i+1]->prior = arr[i];
        	}
	}
	else {
        	for(i = 0; i<n-2; i = i + m){
        		arr[i+m-1]->next = NULL;
        		arr[i]->prior = NULL;
        		exchange(arr[i], arr[i+m-1]);
        	}
        	for (i = 1; i<n-2; i = i + m){
        		arr[i+m-2]->next = arr[i+m-1];
        		arr[i+1]->prior = arr[i];
        	}
		i=n-2;
		arr[i+1]->next=arr[i+2];
		arr[i+1]->prior=arr[i];
       }

	head = arr[0];
	return head;
}

//разбить список на две части относительно индекса n, вторую часть разбить группы по m элементов, поменять в каждой начальный и конечный элемент местами, соединить обратно
MusicalComposition* ChangeList2(MusicalComposition* head, int n, int m){
	MusicalComposition *tmp = head;
	int j;
	for(j=0;j<(n-1);j++) tmp=tmp->next;
	MusicalComposition *curr=tmp->next;
	tmp->next=NULL;
	ChangeList1(curr, m);
	tmp->next=curr;
	return head;
}
