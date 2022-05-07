#include <iostream>
using namespace std;

class B {
public:
	int f(int i) { cout << "f(int) : "; return i + 1; }
};

class D : public B {
public:
	using B::f; //if you want to use base function , then use using concept
	double f(double d) { cout << "f(double) : "; return d + 1.3; }
};

int main() {
	D* pd = new D;
	cout << pd->f(2) << endl;
	cout << pd->f(2.3) << endl;
	return 0;
}