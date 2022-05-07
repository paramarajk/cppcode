#include <iostream>
using namespace std;

class Base {
public:
	virtual void show() {
		cout << "Base show()" << endl;
	}

	void print() {
		cout << "Base print()" << endl;
	}

};

class Derived : public Base {
public:
	void show() {
		cout << "Derived show()" << endl;
	}
};

int main() {
	Base* b = new Derived;
	b->show();
	b->print();
	return 0;
}