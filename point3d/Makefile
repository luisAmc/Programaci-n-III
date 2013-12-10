main : main.o point3d.o
	g++ -o main main.o point3d.o

main.o : main.cpp
	g++ -c main.cpp -o main.o

point3d.o : point3d.cpp point3d.h
	g++ -c point3d.cpp -o point3d.o