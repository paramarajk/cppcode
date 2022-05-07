#include <iostream>
using namespace std;

class Base {
	virtual void method() { cout << "method base" << endl; }
public:
	void base_method() { method(); }

	Base() { cout << "Base ctor" << endl; }
	virtual ~Base() { cout << "Base dtor" << endl; }
};

class A : public Base {

	void method() { cout << "method A" << endl; }
public:
	A() { cout << "A ctor" << endl; }
	~A() { cout << "A dtor" << endl; }
};

int main() {
	Base* b = new A;
	b->base_method();
	delete b;
	return 0;
}

/*
Output : 
Base ctor
A ctor
method A
A dtor
Base dtor
*/