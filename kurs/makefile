all: program clean

clean: program
	rm *.o
program: main.o menu.o labfunc.o kursfunc.o 
	gcc main.o menu.o labfunc.o kursfunc.o -o program

main.o: main.c
	gcc -c main.c

menu.o: menu.c
	gcc -c menu.c

labfunc.o: labfunc.c
	gcc -c labfunc.c

kursfunc.o: kursfunc.c
	gcc -c kursfunc.c
