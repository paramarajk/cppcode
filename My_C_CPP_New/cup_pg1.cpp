/*SomeClass *ptr=new SomeClass();
SomeClass *ptr=new SomeClass;
is it same or not?*/

/*But both are same*/

#include <iostream>
using namespace std;

class sample {
	public:
		void print() {
			cout << "Hello sample" << endl;
		}
};

int main() {
	sample* s1 = new sample();
	s1->print();
	sample* s2 = new sample;
	s2->print();
	return 0;
}
