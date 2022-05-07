#include <iostream>
using namespace std;

class fnd_class {
	int num1;
	fnd_class(int x = 0) : num1(x) {
		cout << "fnd_class const called" << endl;
	}

public:
	void fnd_class_print() {
		cout << "fnd_class_print func called" << endl;
		cout << "Num1 is : " << num1 << endl;
	}

	~fnd_class() {
		cout << "fnd_class dest called" << endl;
	}

	friend int main(); //If we commend this line , will through error: 'fnd_class::fnd_class(int)' is private 
						 //within this context 25 |  fnd_class f(100);
};


int main() {
	fnd_class f(100);
	f.fnd_class_print();
	return 0;
};
