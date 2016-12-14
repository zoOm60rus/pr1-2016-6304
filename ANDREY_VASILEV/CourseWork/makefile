Lab: main.o print_names.o AddToBegin.o count.o push.o removeYear.o removeEl.o createMCList.o createMC.o struct.h func.h
	gcc main.c -o Lab.out print_names.o count.o removeYear.o createMCList.o push.o removeEl.o AddToBegin.o createMC.o 
	rm *.o
main.o: main.c struct.h func.h			
	gcc -c main.c                     
removeYear.o: removeYear.c func.h
	gcc -c removeYear.c
AddToBegin.o: AddToBegin.c struct.h func.h
	gcc -c AddToBegin.c
print_names.o: print_names.c struct.h	
	gcc -c print_names.c
removeEl.o: removeEl.c struct.h  
	gcc -c removeEl.c
count.o: count.c struct.h
	gcc -c count.c   
push.o: push.c struct.h
	gcc -c push.c
createMCList.o: createMCList.c struct.h func.h
	gcc -c createMCList.c
createMC.o: createMC.c struct.h
	gcc -c createMC.c
