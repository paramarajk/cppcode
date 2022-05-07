#include <iostream>

using namespace std;

class Base {
public:
	virtual void func() {
		cout << "Base :: func()" << endl;
	}
};

class Derived : public Base {
public:
	virtual void foo() {
		cout << "Derived :: foo()" << endl;
	}
};

int main() {
	Derived d;
	d.func();
	d.foo();
	return 0;
}

/*
Base :: func()
*/