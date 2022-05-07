#include <iostream>
using namespace std;

class A {
	int a;

public:
	A(int _a = 0) { a = _a;  cout << "A const called" << endl; }
	~A() { cout << "A dest called" << endl; }
};


int main() {
	A(); //temparory object creations
	cout << "hello" << endl;
	cout << sizeof(A) << endl;
	return 0;
}
