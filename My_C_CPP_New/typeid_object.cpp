/*typeid operator allows us to determine whether two objects are the same type.*/
#include <iostream>
#include <typeinfo>
using namespace std;

class Employee {
public:
	void show_id() { cout << "show id func: Employee" << endl; }
};

class Programmer : public Employee {
public:
	void coding() { cout << "coding func : Programmer" << endl; }
};

int main() {
	Employee lee;
	Programmer park;

	//cout << typeid(Programmer) << endl;
	//cout << typeid(Employee) << endl;

	if (typeid(Programmer) == typeid(lee)) {
		cout << "Object is programmer type 1" << endl;
	}

	if (typeid(Programmer) == typeid(park)) {
		cout << "Objcet is programmer type 2" << endl;
	}

	return 0;
}
