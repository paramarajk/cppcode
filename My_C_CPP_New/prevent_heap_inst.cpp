/*Prventing the heap object allocation in c++
Ans: Achiving by keep new operator overload as private"
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class sample {
	void* operator new (size_t size) {
		cout << "new operator called" << endl;
		return malloc(size);
	}

public:
	void print() {
		cout << "sample print func called" << endl;
	}

	sample() {
		cout << "sample const called" << endl;
	}

	~sample() {
		cout << "sample dest called" << endl;
	}
};


int main() {
	//This statement will give error
	/*sample *s = new sample();
	s->print();
	delete s;*/

	sample s1;
	s1.print();
	return 0;
}

/*output
sample const called
sample print func called
sample dest called
*/
