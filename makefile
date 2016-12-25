main: main.o
	gcc -o main main.c createList.c sortirovka.c swap.c
	rm *.o
main.o: main.c
	gcc -c main.c
createList.o: createList.c createList.h abc.h
	gcc -c createList.c 
sortirovka.o: sortirovka.c sortirovka.h abc.h
	gcc -c sortirovka.c
swap.o: swap.c swap.h abc.h
	gcc -c swap.c

