curs: curs.o FUnctions.o 
	gcc  curs.cpp -o cursach.out FUnctions.cpp 
curs.o :curs.cpp
	gcc -c curs.cpp
FUnctions.o: FUnctions.cpp FUnctions.h
	gcc -c FUnctions.cpp 
clean:
	rm -rf *.o
