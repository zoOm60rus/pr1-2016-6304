curs: curs.o functions.o
	gcc curs.cpp -o cursach.out functions.cpp
	rm -rf *.o
curs.o :curs.cpp
	gcc -c curs.cpp
functions.o: functions.cpp functions.h
	gcc -c functions.cpp
