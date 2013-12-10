ihn:    main.o object.o person.o employee.o student.o
	g++ main.o object.o person.o employee.o student.o -o inh

main.o:	object.h person.h employee.h student.h main.cpp
	g++ -c main.cpp
object.o:	object.h object.cpp
	g++ -c object.cpp
person.o:	person.h object.h person.cpp
	g++ -c person.cpp
employee.o:	person.h employee.h employee.cpp
	g++ -c employee.cpp
student.o:	person.h student.h student.cpp
	g++ -c student.cpp
clean:
	rm *.o
cleanall:
	rm *.o inh

