#include <iostream>
using namespace std;

class A {
public:
	virtual void show() { 
		cout << "A show" << endl; 
	}
};
class B : virtual public A {
	void show() { cout << "B show" << endl; }
};
class C : virtual public A {
	void show() { cout << "C show" << endl; }
};
class D : public B, public C {
	void show() { cout << "D show" << endl; }
};

int main() {
	A* d = new D;
	d->show();
	return 0;
}
