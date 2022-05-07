#include <iostream>
using namespace std;

class base {
public:
	base() {
		cout << "Const from base" << endl;
	}
	virtual void show() {
		cout << "show func from base" << endl;
	}
	virtual ~base() {
		cout << "Dest from base" << endl;
	}
};

class derived1 : public base {
public:
	derived1() {
		cout << "Const from derived1" << endl;
	}
	void show() {
		cout << "Show func from derived1" << endl;
	}
	~derived1() {
		cout << "dest from derived1" << endl;
	}
};

class derived2 : public base {
public:
	derived2() {
		cout << "Const from derived2" << endl;
	}
	void show() {
		cout << "Show func from derived2" << endl;
	}
	~derived2() {
		cout << "dest from derived2" << endl;
	}
};


int main() {
	base *b1 = new derived1();  //upcasting d1->b
	base *b2 = new derived2();  //upcastin for d1g d2->b

	b1->show();
	b2->show();

	//dynamic_cast
	derived1 *d1 = dynamic_cast<derived1 *>(b1);  //downcasting b->d1 
	if (d1 != nullptr) {
		cout << "dynamic cast succssful for d1" << endl;
		d1->show();
	} else {
		cout << "dynamic_cast failed for d1" << endl;
	}

	derived2 *d2 = dynamic_cast<derived2 *>(b2);  //downcasting b->d2 
	if (d2 != nullptr) {
		cout << "dynamic cast succssful for d2" << endl;
		d2->show();
	} else {
		 cout << "dynamic_cast failed for d2" << endl;
	}

	//confused downcast for derived class
	derived1 *d3 = dynamic_cast<derived1 *>(b2);  //downcasting b->d2 
	if (d3 != nullptr) {
		cout << "dynamic_cast successful for d3" << endl;
		d3->show();
	} else {
		cout << "dynamic_cast failed for d3" << endl;
	}

	derived2 *d4 = dynamic_cast<derived2 *>(b1);  //downcasting b->d1 
	if (d4 != nullptr) {
		cout << "dynamic_cast successful for d4" << endl;
		d4->show();
	} else {
		cout << "dynamic_cast failed for d4" << endl;
	}
	
	

	delete b1;
	delete b2;
	return 0;
}