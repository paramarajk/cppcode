//It will restrict the inheritance
#include <iostream>
using namespace std;

class base {
	base() { cout << "base: ctor" << endl; }
public:
	~base() {
		cout << "base : dtor" << endl;
	}
	//if we command this below lines getting following errors: 
	//error: 'base::base()' is private within this context
	friend int main();
	//friend class derived; // for allowing inheritance , we need enable this line 
};

class derived : public base {
	derived() { cout << "derived: ctor" << endl; }
	~derived() { cout << "derived: dtor" << endl; }
};

int main() {
	base b;
	//derived d;
	return 0;
}