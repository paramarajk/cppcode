#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class student {
	char* name;
	int age;

public:
	student(int nage = 0, const char* ptr = NULL) : age(nage), name(NULL) {
		name = new char(strlen(ptr)+1);
		strcpy(name, ptr);
		cout << "student const called" << endl;
	}

	student(const student& obj) {
		age = obj.age;
		name = new char(strlen(obj.name)+1);
		strcpy(name, obj.name);
		cout << "student copy const called" << endl;
	}

	student& operator=(const student& obj) {
		if (this != &obj) {
			age = obj.age;
			delete[] name;
			name = new char(strlen(obj.name)+1);
			strcpy(name, obj.name);
			cout << "student Assignment operator calle" << endl;
		}
		return *this;
	}

	void student_print() {
		cout << "student_print func called" << endl;
		cout << "Name is : " << name << endl;
		cout << "Age is : " << age << endl;
	}

	~student() {
		if (name != NULL) {
			delete[] name;
		}
		cout << "student dest called" << endl;
	}

};


int main() {
	student s1(25, "Param");
	s1.student_print();
	student s2 = s1;
	s2.student_print();
	student s3;
	s3 = s2;
	s3.student_print();
}
