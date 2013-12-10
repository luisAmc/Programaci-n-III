#include "object.h"
#include "person.h"
#include "student.h"
#include "employee.h"
#include "kid.h"
#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;


int main(int argc, char* argv[]){
	vector<Object*> v;

	v.push_back(new Person("Juan", 12));
	v.push_back(new Person("Denisse", 19));
	v.push_back(new Student("Alejandra", 19, 11211011));
	v.push_back(new Employee("Allan", 21, 20000));

	cout << "-----------------------------------------------------" << endl;

	for (int i=0; i<v.size(); i++){
		//cout << typeid(*v[i]).name() << endl;
		cout << v[i]->toString() << endl;
		if (typeid(*v[i]) == typeid(Person)){
			cout << "It is a Person!" << endl;
			Person* pp = dynamic_cast<Person*>(v[i]);
			pp->bday();
		}
		if (typeid(*v[i]) == typeid(Employee)){
			cout << "It is an Employee!" << endl;
			Employee* ep = dynamic_cast<Employee*>(v[i]);
			ep->promote(0.25);
		}
		if (typeid(*v[i]) == typeid(Student)){
			cout << "It is a Student!" << endl;
			Student* sp = dynamic_cast<Student*>(v[i]);
			sp->addGrade(75, 4);
			sp->addGrade(100, 2);
		}
		cout << endl;
	}

	cout << "-----------------------------------------------------" << endl;
	for (int i=0; i<v.size(); i++){
		cout << v[i]->toString() << endl;
	}
	cout << "-----------------------------------------------------" << endl;
	for (int i=0; i<v.size(); i++){
		cout << typeid(*v[i]).name() << endl;
		if (typeid(*v[i]) == typeid(Object))
			cout << "Type Id Igual a Object" << endl;

	}


	for (int i=0; i<v.size(); i++)
		delete v[i];

	
	return 0;
}
