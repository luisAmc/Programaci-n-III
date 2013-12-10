main : main.o square.o rect.o quad.o
	g++ -o main main.o quad.o rect.o square.o

main.o : square.o rect.o quad.o main.cpp
	g++ -c main.cpp -o main.o

square.o : quad.o rect.o square.cpp
	g++ -c square.cpp -o square.o

rect.o : quad.o rect.cpp 
	g++ -c rect.cpp -o rect.o

quad.o : quad.cpp
	g++ -c quad.cpp -o quad.o