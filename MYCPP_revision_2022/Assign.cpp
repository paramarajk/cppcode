#include <iostream>
#include <string.h>
using namespace std;

class assign {
	char *_name;
	int _age;
public:
	assign(const char *name = NULL, int age = 0) {
		if (name != NULL) {
			_name = new char[strlen(name)];
			strcpy(_name, name);
			_age = age;
		} else {
			_age = 0;
			_name = NULL;
		}
		cout << "Constructor called" << endl;
	}

	~assign() {
		if (_name != NULL) {
			delete [] _name;
			_name = NULL;
			cout << "destruced object" << endl;
		}
	}

	assign(const assign& obj) {
		if(obj._name != NULL) {
			_name = new char[strlen(obj._name)];
			strcpy(_name, obj._name);
			_age = obj._age;
		}
		cout << "Copy constructor called" << endl;
	} 

	assign& operator =(const assign& obj) {
		if (this != &obj) {
			if (_name != NULL) {
				delete [] _name;
				_name = NULL;
			}
			_name = new char[strlen(obj._name)];
			strcpy(_name, obj._name);
			_age = obj._age;
			cout << "Assignment operator called" << endl;
		}
		return *this;
	}

	void print() {
		cout << "Print func called" << endl;
		if (_name != NULL) {
			cout << "Name of the persion : " << _name << endl;
			cout << "Age of the persion : " << _age << endl;	
		} else {
			cout << "Name and age is NULL" << endl;
		}
		
	}
};

int main() {
	assign a("Param", 35);
	a.print();
	assign a1 = a;
	a1.print();
	assign a2;
	a2.print();
	a2 = a;
	a2.print();
	return 0;
}