#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class A {
public:
	virtual void func() {
		cout << "Hello from A" << endl;
	}
};

class B : public A {
private:
	void func() {
		cout << "Hello from B" << endl;
	}
};

int main() {
	A* ptr = new B();
	ptr->func();
	return 0;
}