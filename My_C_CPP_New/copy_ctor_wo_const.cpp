/* c-plus-plus-interview-questions
Why do you need the const in a copy constructor? For example, if you have Foo (const Foo &), why do you need the const?
ANS: So that the constructor do not change the object from which copy is being made.
but w.o const this program will compiled succesfully
*/

#include <iostream>
using namespace std;

class sample {

public:
	sample() {}
	sample(sample& obj) {

	}
};


int main() {
	sample s;
	sample s1(s);

	return 0;
}
