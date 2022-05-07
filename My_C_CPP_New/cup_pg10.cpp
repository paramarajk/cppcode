/* goldman-sachs-interview-questions
There is a class A which contains just one parameterized constructor A(int a).
How would you initialize an array of objects of this class.
ANS : using vector , array
*/

#include <iostream>
#include <vector>
using namespace std;

class test {
	int x;
public:
	test(int i = 0) : x(i) {
		cout << "test const called" << endl;
	}

	void print() {
		cout << "X is : " << x << endl;
	}

	~test() {
		cout << "test dest called" << endl;
	}
};


int main() {
	/*first solution*/
	cout << "using array" << endl;
	test arr_t[5] = { 1, 2, 3, 4, 5 };
	cout << "================Array==============" << endl;
	for (auto i : arr_t) {
		i.print();
	}

	/*second solution*/
	cout << "Using vector" << endl;
	vector<test> mvec(5, test(1));
	cout << "================vector=============" << endl;
	for (auto i : mvec)  {
		i.print();
	}
	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/tricky_question/Interview_questions/careerup=>./pg10
using array
test const called
test const called
test const called
test const called
test const called
Using vector
test const called
test dest called
test dest called
test dest called
test dest called
test dest called
test dest called
test dest called
test dest called
test dest called
test dest called
test dest called
*/
