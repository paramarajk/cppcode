/*
 * This is class and object learning
 */

#include <iostream>
using namespace std;

class sample {
	int _num1, _num2;
public:
	sample(int n1 = 0, int n2 = 0) : _num1(n1), _num2(n2) {
		cout << "sample ctor called" << endl;
	}

	~sample() {
		cout << "sample dtor called" << endl;
	}

	void sample_print() {
		cout << "sample_print func called" << endl;
		cout << "Num1 is : " << _num1 << endl;
		cout << "Num2 is : " << _num2 << endl;
	}

	void sample_set(int n1, int n2) {
		_num1 = n1;
		_num2 = n2;
		cout << "sample_set func called" << endl;
	}
};


int main() {
	sample s1;
	s1.sample_set(100, 200);
	s1.sample_print();

	sample s2(10, 20);
	s2.sample_print();

	return 0;
}
