#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"struct.h"
#include"funk.h"
#include"funk2.h"
int main(){
	int a = 0;
	int l;
	int year;
	char name[80];
	char author[80];
	printf("Создание списка\nВведите длину списка\n");
    	scanf("%d", &l);
	char** names = (char**)malloc(sizeof(char*)*l);
	char** authors = (char**)malloc(sizeof(char*)*l);
	int* years = (int*)malloc(sizeof(int)*l);
	int i;
	for(i=0;i<l;i++){
		printf("Введите название, автора композиции и год создания\n");
		scanf("%s%s%d", name, author, &year);
		names[i] = (char*)malloc(sizeof(char*)*(strlen(name)+1));
		authors[i] = (char*)malloc(sizeof(char*)*(strlen(author)+1));
		strcpy(names[i], name);
		strcpy(authors[i], author);
		years[i]=year;
	}
	MusicalComposition* head = createMusicalCompositionList(names, authors, years, l);
	for(i=0; i<l; i++){
		free(names[i]);
		free(authors[i]);
	}
        free(years);
        while(1==1){
 		printf("1)Добавление нового элемента в конец списка;\n2)Удаление определенного элемента;\n3)Вывод длины списка;\n4)Вывод названий композиций;\n5)Разделить список на две части относительно индекса n, вторую часть разделить на группы по m элементов, соединить элементы обратно в список;\n6)Разделись список на две равные части(или же индекс центрального элемента округлить в большую сторону), скопировать первую часть и вставить в середину\n7)Выход\n");
		scanf("%d", &a);
        	if(head==0){
                	while((a != 1) || (a != 0)){
                	printf("Если хотите продолжить работу, введите 1, если хотите выйти, введите 0\n");
                	scanf("%d", &a);
			}
                	if(a == 0) exit(0);
                 	else{
                        	printf("Введите длину списка\n");
                        	scanf("%d", &l);
                        	printf("Введите название, автора композиции и год создания\n");
                        	scanf("%s%s%d", name, author, &year);
                        	head = createMusicalComposition(name, author, year);
                        	for (i=0;i<l-1;i++) {
                         		printf("Введите название, автора и год создания\n");
                         		scanf("%s%s%d", name, author, &year);
                         		push(head, createMusicalComposition(name, author, year));
                         	}
			}	
		}
        	else
        	switch(a){
                	case 1:{
 				printf("Введите название, автора композиции и год создания\n");
                        	scanf("%s%s%d", name, author, &year);
                        	push(head, createMusicalComposition(name, author, year));
                        	break;
                        }
                	case 2:{
                        	printf("Введите название нужной композиции\n");
                        	scanf("%s", name);
                        	removeEl(head, name);
                        	break;}
                	case 3:{
                        	int c = count(head);
                        	printf("%d - количество композиций в списке\n", c);
				break;
                        }
                	case 4:{
                        	print_names(head);
                        	break;
                        }
                	case 5:{
				int m;
                        	int n;
                        	printf("Введите m и n");
                        	scanf("%d %d",&n, &m);
                        	ChangeList2(head,n,m);
				print_list(head);
                        	break;
			}
                	case 6:{
                        	head = ChangeList(head);
                        	break;
                        }
                	case 7: {
                        	exit(0);
                        }
		}
		printf("Если вы хотите продолжить работу, введите 1, если хотите выйти, введите 0\n");
		scanf("%d", &a);
		if(a == 0) break;
		}
	return 0;
}

