#include <iostream>
using namespace std;

class const_class {
	const int num1; //we should initialize in constructor itself
public:
	const_class(int x = 0) : num1(x) {
		cout << "const_class const called" << endl;
	}
	~const_class() {
		cout << "const_class dtor called" << endl;
	}

	void print() {
		cout << "print func called" << endl;
		cout << "num1 is : " << num1 << endl;
	}

};


int main() {
	const_class c(100);
	c.print();
	return 0;
}
