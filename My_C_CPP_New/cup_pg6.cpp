#include <iostream>
using namespace std;

class base {
public:
	int var1;
	base(int var) : var1(var) {

	}

	void print() {
		cout << "var1 is : " << var1 << endl;
	}
};

/*derived class calling the base class ctor before setting the value for var2
so that reason var1 of base having garbage value*/
class derived : public base {
public:
	int var2;
	derived(int var) : base(var2++), var2(var++) {

	}

	void print() {
		cout << "var2 is : " << var2 << endl;
		cout << "var1 is : " << var1 << endl;
	}
};


int main() {
	derived d1(100);
	d1.print();
	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/tricky_question/Interview_questions/careerup=>./pg6
var2 is : 100
var1 is : -559038737
*/

