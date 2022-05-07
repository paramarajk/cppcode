/*functor is a parameterized function*/
#include <iostream>
using namespace std;

class A {
	int id;
public:
	A(int i) : id(i) { cout << "ctor called" << endl; }
	void operator() (const char* _buf) {
		cout << "A : " << _buf << endl;
		cout << "id is : " << id << endl;
	}
};

int main() {
	A(1024) ("hello");
	A obj(10);
	obj("Hello 10");
	return 0;
}
