#include <iostream>
using namespace std;

struct B {
	B() {
		cout << "B::B()" << endl;
	}

	int n;
};

struct X : virtual B {
	X() {
		cout << "X::X()" << endl;
	}
};

struct Y : virtual B {
	Y() {
		cout << "Y::Y()" << endl;
	}
};

struct Z : B {
	Z() {
		cout << "Z::Z()" << endl;
	}
};

struct A : X, Y, Z {
	A() {
		X::n = 1;
		Y::n = 2;
		Z::n = 3;
		cout << "A::A(), " << X::n << ", " << Y::n << ", " << Z::n << endl;
	}
};

int main() {
	A a;
}

/*
B::B()
X::X()
Y::Y()
B::B()
Z::Z()
A::A(), 2, 2, 3
*/