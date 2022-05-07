#include <iostream>
using namespace std;

class base {
	int n;
public:
	base(int no = 0) : n(no) {
		cout << "base conat called" << endl;
	}

	~base() {
		cout << "base dest called" << endl;
	}
};

class derived : public base {
	int d;
public:
	derived(int d1 = 0) : d(d1) {
		cout << "derived const called" << endl;
	}

	~derived() {
		cout << "derived dest called" << endl;
	}
};

int main() {
	derived d;
	base& b = d;

	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/tricky_question/Interview_questions/careerup=>./pg11
base conat called
derived const called
derived dest called
base dest called
*/
