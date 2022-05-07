/* goldman-sachs-interview-questions
define class such that you can make object of this class on a heap but not on the stack
ANS: 1)make the destructor as a private member function
2)add a public function which will have this statement :*/


#include <iostream>
using namespace std;

class base {
	~base() {
		cout << "base dest called" << endl;
	}
public:
	base() {
		cout << "base const called" << endl;
	}
	void Clearbptr() {
		delete this;
	}
};

int main() {
	/*base b will call the ctor and dest, here i made the dtor as private.
	because of this reason i am unable to make base obj in stack
	error: 'base::~base()' is private*/
	//base b;

	/*here base pointer will call ctor, new operator,so that reason, i am able to create pointer of base*/
	base* b1 = new base;

	/*delete opeator will call while deleting the pointer of base
	it will call the base dtor , because of this reson i am unable to deallocate the memory allocated from heap using delete
	without affecting anything*/
	//delete b1;	
	/*for this problem i added Clearbptr function , will do that*/

	b1->Clearbptr(); /*it will delete the de-allocated memory from heap*/
	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/tricky_question/Interview_questions/careerup=>./pg8
base const called
base dest called
*/
