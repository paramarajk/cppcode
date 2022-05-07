/*playing with virtual pointer class*/

#include <iostream>
using namespace std;

class base {
public:
	base() {
		cout << "base const called" << endl;
	}

	virtual ~base() {
		cout << "base dest called" << endl;
	}

	virtual void show() {
		cout << "base show func called" << endl;
	}
};

class derived : public base {
public:
	derived() {
		cout << "derived const called" << endl;
	}

	~derived() {
		cout << "derived dest called" << endl;
	}

	void show() override {
		cout << "derived show func called" << endl;
	}
};

int main() {
	base* b = new derived;
	b->show();
	cout << "Sizeof(base) : " << sizeof(base) << endl;
	cout << "Sizeof(derived) : " << sizeof(derived) << endl;
	delete b;

	return 0;
}
/*
output:
base const called
derived const called
derived shoe func called
Sizeof(base) : 4
Sizeof(derived) : 4
derived dest called
base dest called
*/
