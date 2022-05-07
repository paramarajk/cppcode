/*mutable keyword*/

#include <iostream>
using namespace std;

class sample {
	mutable int count;
public:
	sample(int cnt = 0) : count(cnt) {
		cout << "const called" << endl;
	}

	~sample() {
		cout << "Dest called" << endl;
	}

	void set_count() const {
		count = 1000; //mutable variable can be modified inside the const func
	}

	void print() {
		cout << "The value of count is : " << count << endl;
	}
};

int main() {
	sample s1;
	s1.set_count();
	s1.print();
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/tricky_question/Interview_questions=>./mutable
const called
The value of count is : 1000
Dest called
*/
