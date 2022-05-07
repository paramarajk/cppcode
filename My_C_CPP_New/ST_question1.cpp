#include <iostream>
using namespace std;

struct B {
	virtual void f() {
		cout << "B::f" << endl;
	}

	virtual ~B() {
		cout << "B::~B()" << endl;
	}
};

struct C {
	virtual void f() {
		cout << "C::f" << endl;
	}

	virtual ~C() {
		cout << "C::~C()" << endl;
	}
};

struct D : B, C {
	virtual ~D() {
		cout << "D::~D()" << endl;
	}
};

int main() {
	B* b = new D;
	C* c = dynamic_cast<C*> (b);
	D* d = dynamic_cast<D*> (b);
	d->f();
	delete c;
}

/*
Output :
D::f is ambiguous
*/