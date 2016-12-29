main: struct.h main.o funk.o funk2.o
	gcc main.o -o main funk.o funk2.o
	rm *.o
main.o: main.c struct.h
	gcc -c main.c
funk.o: funk.c funk.h struct.h
	gcc -c funk.c
funk2.o: funk2.c funk2.h struct.h
	gcc -c funk2.c
