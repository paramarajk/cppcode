#include <iostream>
using namespace std;

class sample {
public:
	virtual void show() {
		cout << "sample: show" << endl;
	}
};

class subclass : public sample {
public:
	void show() {
		cout << "subclass: show" << endl;
	}
};

class subclass1 : public subclass {
public:
	void show() {
		cout << "subclass1: show" << endl;
	}
};

int main() {
	subclass* s = new subclass1;
	s->show();
	return 0;
}