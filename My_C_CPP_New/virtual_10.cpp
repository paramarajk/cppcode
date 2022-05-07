#include <iostream>
using namespace std;

class base {
public:
	virtual void show() {
		cout << "base show func called" << endl;
	}
};

class derived : public base {
public:
	void show() {
		cout << "derived show func called" << endl;
	}
};

int main() {
	base* b = new derived;
	cout << "Size of base is : " << sizeof(base) << endl;
	cout << "Size of derived is : " << sizeof(derived) << endl;
	b->show();

	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/virtual_concept=>./pg1
Size of base is : 4
Size of derived is : 4
derived show func called
*/
