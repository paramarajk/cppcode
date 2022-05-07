#include <iostream>
using namespace std;

class base {
public:
	virtual void show() { cout << "base show" << endl; }
	virtual void print() { cout << "base print" << endl; }
};

class derived1 : public base {
public:
	void show() { cout << "derived1 show" << endl; }
	//virtual void print() { cout << "derived1 print" << endl; }
};

class derived2 : public base {
public:
	//virtual void show() { cout << "derived2 show" << endl; }
	void print() { cout << "derived2 print" << endl; }
};

int main() {
	base* b = new derived1;
	b->show(); b->print();
	base* b1 = new derived2;
	b1->show(); b1->print();

	cout << "sizeof(base) is : " << sizeof(base) << endl;
	cout << "sizeof(derived1) is : " << sizeof(derived1) << endl;
	cout << "sizeof(derived2) is : " << sizeof(derived2) << endl;

	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/virtual_concept=>./pg2
derived1 show
base print
base show
derived2 print
sizeof(base) is : 4
sizeof(derived1) is : 4
sizeof(derived2) is : 4
*/


