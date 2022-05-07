/*block the inheritance and allow to create object for base class*/
#include <iostream>
using namespace std;

class final {
	final() { cout << "final ctor called" << endl; }
	~final() { cout << "final dtor called" << endl; }
	friend class base;
};

class base : virtual final {
public:
	base() { cout << "base ctor called" << endl; }
	~base() { cout << "base dtor called" << endl; }
};

class derived : public base {
public:
	derived() { cout << "derived ctor called" << endl; }
	~derived() { cout << "derived dtor called" << endl; }
};

int main() {
	base b;
	cout << "SIZEOF(FINAL) : " << sizeof(final) << endl;
	cout << "SIZEOF(BASE) : " << sizeof(base) << endl;
	//derived d;
	return 0;
}