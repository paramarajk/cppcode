/*override keyword*/

#include <iostream>
using namespace std;

class base {
public:
	virtual void print() {
		cout << "Hello print : Base" << endl;
	}

	virtual void show(int val) {
		cout << "Hello show : Base with int arg" << endl;
	}
};

class derived : public base {
public:
	void print() override {
		cout << "Hello print : derived" << endl;
	}

	virtual void show(float val) {
		cout << "Hello show : derived with float arg" << endl;
	}

	void show(int val) override {
		cout << "Hello show : Derived with int arg" << endl;
	}
};

int main() {
	base* b = new derived;
	b->print();
	b->show(10);
	return 0;
}
