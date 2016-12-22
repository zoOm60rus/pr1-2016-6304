kurswork.out : main.cpp functionsFromLab.cpp kursFunctions.cpp
	g++ main.cpp kursFunctions.cpp functionsFromLab.cpp -o kurswork.out
main.o: main.cpp
	g++ -c main.cpp
functionsFromLab.o: functionsFromLab.cpp functionsFromLab.h
	g++ -c functionsFromLab.cpp
kursFunctions.0: kursFunctions.cpp kursFunctions.h
	g++ -c kursFunctions.cpp
clean:
	rm -rf *.o

