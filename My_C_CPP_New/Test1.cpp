#include <iostream>
using namespace std;

class A {
public:
	A() {}
	virtual void fun(int s) const {
		cout << "In A" << endl;
	}
};

class B : public A {
public:
	B() {}
	
	virtual void fun(int i) const {
		cout << "In B" << endl;
	}
};

int main()
{
	A* p;
	B b;
	p = &b;
	p->fun(10);

	return 0;
}