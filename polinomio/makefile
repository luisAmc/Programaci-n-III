main: main.o polynomial.o
	g++ main.o polynomial.o -o main

main.o: polynomial.h main.cpp
	g++ -c main.cpp

polynomial.o: polynomial.h polynomial.cpp
	g++ -c polynomial.cpp

clean:
	rm *.o

cleanall:
	rm *.o main