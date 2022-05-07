#include <iostream>
using namespace std;

class base {
public:
	virtual void show() { cout << "base show" << endl; }
};

class derived1 : public base {
public:
	void show() { cout << "derived1 show" << endl; }
};

class derived2 : public derived1 {
public:
	void show() { cout << "derived2 show" << endl; }
};

int main() {
	base* b = new derived2;
	cout << "sizeof(base) is : " << sizeof(base) << endl;
	cout << "sizeof(derived1) is : " << sizeof(derived1) << endl;
	cout << "sizeof(derived2) is : " << sizeof(derived2) << endl;
	b->show();

	return 0;
}

/*
ramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/virtual_concept=>./pg3
sizeof(base) is : 4
sizeof(derived1) is : 4
sizeof(derived2) is : 4
derived2 show
*/
