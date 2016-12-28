#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"

int main()
{
	int x=1;
	int key = 0;
	int length;
	int year;
	char name[80];
	char author[80];
	printf("Let's start creating Musical Composition List!\n Enter the length of the List:\n");
	scanf("%d", &length);
	char** names = (char**)malloc(sizeof(char*)*length);
	char** authors = (char**)malloc(sizeof(char*)*length);
	int* years = (int*)malloc(sizeof(int)*length);
	for (int i=0;i<length;i++)
	{
		printf("Enter the name of the song, the author and the year of composition:\n");
		scanf("%s%s%d", name, author, &year);
		names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
		authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));
		strcpy(names[i], name);
		strcpy(authors[i], author);
	}
MusicalComposition* head = createMusicalCompositionList(names, authors, years, length);
for(int i=0; i<length; i++)	
{
	free(names[i]);
	free(authors[i]);
}
free(years);
while(x)	
{
	printf("1.Add an element to the List.\n2.Remove an element.\n3.Count elements.\n4.Print names of the List.\n5.Insert the 3 elements in the middle of the List.\n6.Change the lowercase to uppercase.\n7.Quit\n");
	scanf("%d", &key);
	if(head == 0){
	while((key != 1) || (key != 0)){}
	if(key == 0)
	{
		break;
		x = 0;
	}
	else
	{
	printf("Enter the length of the List:\n");
	scanf("%d", &length);
	printf("Enter the name of the song, the author and the year of composition:\n");
	scanf("%s%s%d", name, author, &year);
	head = createMusicalComposition(name, author, year);
	for (int i=0;i<length-1;i++) {
	printf("Enter the name of the song, the author and the year of composition:\n");
	scanf("%s%s%d", name, author, &year);
	push(head, createMusicalComposition(name, author, year));
	}
	}
	}
	else
	switch(key){
	case 1:
	{
		printf("Enter the name of the song, the author and the year of composition:\n");
		scanf("%s%s%d", name, author, &year);
		push(head, createMusicalComposition(name, author, year));
		print_names(head);
		break;
	}
	case 2:
	{
	printf("Enter the name of the song to remove:\n");
	scanf("%s", name);
	removeEl(head, name);
	print_names(head);
	break;
	}
	case 3:
	{
	int c = count(head);
	if(c>1)
	printf("There are %d elements in the List\n", c);
	else
	printf("There is %d element in the List\n", c);
	break;
	}
	case 4:
	{
	print_names(head);
	break;
	}
	case 5:
	{
	function(head);
	print_names(head);
	break;
	}
	case 6:
	{
	change(head);
	print_names(head);
	break;
	}
	case 7:
	{
	x = 0;
	break;
	}
	default:
printf("Enter another number\n") ;
	}
	printf("If you want to create a List PRESS 1, but if you want to exit PRESS 0\n");
	scanf("%d", &key);
	if(key == 0) break;
	}
	return 0;
	}
