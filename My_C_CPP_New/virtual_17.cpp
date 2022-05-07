#include <iostream>
using namespace std;

class derived {
	int num1;
public:
	derived(int x = 0) : num1(x) { cout << "constructor : derived" << endl; }
	~derived() { cout << "dest : derived" << endl; }
	void show() { cout << "Num1 is : " << num1 << endl; }
};

class base {
	derived* d;
public:
	base() : d(new derived) {
		cout << "constructor : base" << endl;
		d->show();
	}

	~base() {
		if (d != NULL) {
			delete d;
		}
		cout << "dest : base" << endl;
	}
};

int main() {
	base b;
	return 0;
}

/*
output : 
constructor : derived
constructor : base
Num1 is : 0
dest : derived
dest : base

*/