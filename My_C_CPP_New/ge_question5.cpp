#include <string>
#include <iostream>
using namespace std;

class B {
public:
	B(const string& ss) { cout << "B ctor" << endl; f(ss); }
	virtual void f(const string&) { cout << "B::f" << endl; }
};

class D : public B {
	string s;
public:
	D(const string& ss) : B(ss) { cout << "D ctor" << endl; }
	void f(const string& ss) { cout << "D::f" << endl; s = ss; }
};

int main() {
	D d("Hello");
	return 0;
}