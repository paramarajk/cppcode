#include <iostream>
using namespace std;

class A {
protected:
	int val;
public:
	A(int _val = 0) : val(_val) { cout << "A const" << endl; }
	void show() { cout << "A show" << endl; }
};
class B : virtual public A {
public:
	B() { cout << "B const" << endl; }
	void show() { cout << "B show" << endl; }
};
class C : virtual public A {
public:
	C() { cout << "C const" << endl; }
	void show() { cout << "C show" << endl; }
};
class D : public B, public C {
public:
	D() { cout << "D const" << endl; }
	void show() { cout << "D show" << endl; }
};

int main() {
	D d;
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	cout << sizeof(D) << endl;
	return 0;
}


/*
sizeof(A) : 4 bytes (val) = 4 bytes
sizeof(B) : 4 bytes (val) + 4 bytes (vptr) = 8 bytes
sizeof(C) : 4 bytes (val) + 4 bytes (vptr) = 8 bytes
sizeof(D) : 4 bytes (val) + 4 bytes (B vptr) + 4 bytes (C vptr) = 12 bytes
*/
