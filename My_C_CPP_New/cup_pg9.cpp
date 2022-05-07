/* goldman-sachs-interview-questions
define a class such that you can make object of this class but you can not inherit this class.
ANS : using final keyword , we can restric the inheritance from base class
compiling this program : g++ pg9.cpp -o pg9 -std=c++11
*/

#include <iostream>
using namespace std;

class base final {
public:
	base() {
		cout << "base const called" << endl;
	}

	~base() {
		cout << "base dest called" << endl;
	}
};

class derived : public base {
public:
	derived() {
		cout << "derived const called" << endl;
	}

	~derived() {
		cout << "derived dest called" << endl;
	}
};


int main() {
	base b;

	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/tricky_question/Interview_questions/careerup=>g++ pg9.cpp -o pg9
pg9.cpp:10:7: warning: override controls (override/final) only available with -std=c++11 or -std=gnu++11 [enabled by default]
 class base final {
	   ^
pg9.cpp:21:7: error: cannot derive from 'final' base 'base' in derived type 'derived'
 class derived : public base {
	   ^
*/
