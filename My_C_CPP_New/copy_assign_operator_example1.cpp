#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string.h>
#include "mystring.h"
using namespace std;

class assign {
	char* _name;
	int _age;
public:
	assign(const char* name = NULL, int age = 0) : _age(age) {
		if (name != NULL) {
			_name = new char[strlen(name)+1];
			strcpy(_name, name);
		}
		else {
			_name = NULL;
		}
		cout << "ctor called" << endl;
	}

	~assign() {
		if (_name != NULL) {
			delete[] _name;
			_name = NULL;
		}
		cout << "dtor called" << endl;
	}

	assign& operator=(const assign& obj) {
		if (this != &obj) {
			if (_name != NULL) {
				delete[] _name;
				_name = NULL;
			}
			_name = new char[strlen(obj._name)+1];
			strcpy(_name, obj._name);
			_age = obj._age;
		}
		cout << "assignment operator called" << endl;
		return *this;
	}

	assign(const assign& obj) : _age(obj._age) {
		if (obj._name != NULL) {
			_name = new char[strlen(obj._name)+1];
			strcpy(_name, obj._name);
		}
		cout << "copy constructor called" << endl;
	}

	void print() {
		cout << "Name is : " << _name << endl;
		cout << "Age is : " << _age << endl;
	}
};

int main() {
	assign a1("David", 32);
	assign a2;
	a2 = a1;
	a1.print();
	a2.print();
	assign a3 = a2;
	a3.print();
	return 0;
}