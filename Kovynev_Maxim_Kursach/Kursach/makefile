Kursach: themainesthnik.h sort.o removeoddel.o main.o print_names.o count.o push.o createList.o
	gcc main.o -o Kursach_Main.out sort.o removeoddel.o print_names.o count.o push.o createList.o
	rm *.o

sort.o: sort.c sort.h struct.h
	gcc -c sort.c 
removeoddel.o: removeoddel.c removeoddel.h struct.h
	gcc -c removeoddel.c
print_names.o:  print_names.c print_names.h struct.h
	gcc -c print_names.c
count.o:  count.c count.h struct.h
	gcc -c count.c
main.o: main.c themainesthnik.h
	gcc -c main.c
push.o: push.c push.h struct.h
	gcc -c push.c 
createList.o: createList.c createList.h struct.h
	gcc -c createList.c
