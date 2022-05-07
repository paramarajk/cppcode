#include <iostream>
using namespace std;

class A {
public:
	virtual void dummy() { cout << "A dummy" << endl; }
};

class B : public A {
public:
	void dummy() { cout << "B dummy" << endl; }
};

int main() {
	A* a = new B;
	B* b = static_cast<B*>(a);
	b->dummy();

	return 0;
}
