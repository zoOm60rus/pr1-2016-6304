#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct MusicalComposition {

	char name[80];
	char author[80];
	int year;
	struct MusicalComposition* next;
	struct MusicalComposition* prev;
};

typedef struct MusicalComposition MusicalComposition;

void PermutationRegarding_n(MusicalComposition* ptr, int n){

	MusicalComposition *headprev; 
	int i=1;
	char fname[80];
	char fauthor[80];
	int fyear;

	while (i!=n){ptr=ptr->next; i++;}

	headprev=ptr;

	while ((headprev->prev) && (ptr->next)){

		

		strcpy(fname,headprev->prev->name);
		strcpy(fauthor,headprev->prev->author);
		fyear=headprev->prev->year;

		strcpy(headprev->prev->name,ptr->next->name);
		strcpy(headprev->prev->author,ptr->next->author);
		headprev->prev->year=ptr->next->year;

		strcpy(ptr->next->name,fname);
		strcpy(ptr->next->author,fauthor);
		ptr->next->year=fyear;

		headprev=headprev->prev;
		ptr=ptr->next;
	}
}

MusicalComposition* PermutationRegardingMiddle(MusicalComposition *head, int k){

	MusicalComposition *ptr=head;
	MusicalComposition *saveHead=head;

	if ((k % 2)==0) k=k/2; else k=(k-1)/2;

	while (ptr->next) ptr=ptr->next; 

	ptr->next=head;
	head->prev=ptr;

	for (int i=1;i<k;i++) head=head->next; 

	head->next->prev=NULL;
	saveHead=head->next;
	head->next=NULL;

	return saveHead;
}
