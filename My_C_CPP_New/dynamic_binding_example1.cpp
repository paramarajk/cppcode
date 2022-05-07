#include <iostream>
using namespace std;

class base {
public:
	base() { cout << "base ctor called" << endl; }
	base(const base& obj) {
		cout << "copy ctor called : base" << endl;
	}
	virtual void show() { cout << "show func called : base " << endl; }
	virtual ~base() { cout << "base dtor called" << endl; }
};

class derived : public base {
public:
	derived() { cout << "derived ctor called" << endl; }
	derived(const derived& obj) {
		cout << "copy ctor called : derived" << endl;
	}
	void show() { cout << "show func called : derived" << endl; }
	~derived() { cout << "derived dtor called" << endl; }
};

int main() {
	derived d;
	base* b = &d;
	b->show();
	base b1 = d; //it will do static binding, because no pointer/ref used here, calling the copy ctor of base
	b1.show(); // it will call the base show function
	cout << "Sizeof b : " << sizeof(b) << endl;
	cout << "Sizeof b1 : " << sizeof(b1) << endl;
	return 0;
}
