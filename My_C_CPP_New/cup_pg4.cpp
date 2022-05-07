#include <iostream>
using namespace std;

class base {
	int n;
public:
	base() {
		cout << "base const called" << endl;
	}

	virtual ~base() {
		cout << "base dest called" << endl;
	}

	virtual void method() = 0;
};

void base::method() { cout << "base method" << endl; n = 0; }

class D1 : public base {
	int c, d;
};

class D2 : public D1 {
	int i;
	void method() { cout << "D2 method" << endl; i = 2; }
};

int main() {
	cout << "sizeof(base) : " << sizeof(base) << endl;
	cout << "sizeof(D1) : " << sizeof(D1) << endl;
	cout << "sizeof(D2) : " << sizeof(D2) << endl;

	base* b1 = new D2;
	b1->method();
	delete b1;

	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/tricky_question/Interview_questions/careerup=>./pg4
sizeof(base) : 8
sizeof(D1) : 8
sizeof(D2) : 12
base const called
D2 method
base dest called
*/
