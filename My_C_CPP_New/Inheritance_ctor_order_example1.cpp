#include <iostream>
using namespace std;

class base {
public:
	base() {
		cout << "base const called" << endl;
	}

	~base() {
		cout << "base dest called" << endl;
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
};


int main() {
	derived d;
	return 0;
}
