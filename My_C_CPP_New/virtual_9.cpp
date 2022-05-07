#include <iostream>
using namespace std;

class base {
public:
	virtual void show() { cout << "In base show" << endl; }
};

class derived : public base {
public:
	void show() { cout << "In derived show" << endl; }
};

int main() {
	base* b = new derived;
	b->show();
	derived* d = new base;
	d->show();
	derived* d = dynamic_cast<derived *> (new base);
	if (d) {
		cout << "Dynamic cast is successful " << endl;
	}
	else {
		cout << "Dynamic cast is not successful" << endl;
	}   ///This will give "Dynamic cast is not successful" because conversion from base to derived not valid
	
	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/virtual_concept/geekfgeek=>g++ pg9.cpp -o pg9
p9.cpp: In function 'int main()':
p9.cpp:17:19: error: invalid conversion from 'base*' to 'derived*' [-fpermissive]
  derived *d = new base;
				   ^
*/

