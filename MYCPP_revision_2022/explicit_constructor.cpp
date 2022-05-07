/* aggregate intialization*/
#include <iostream>
using namespace std;

class sample {
	int num1, num2;
	double dnum;

public:
	explicit sample(int n1 = 0, int n2 = 0, double dn1 = 0) : num1(n1), num2(n2), dnum(dn1) {
		cout << "ctor called" << endl;
	}

	~sample() {
		cout << "dtor called" << endl;
	}

	void print() {
		cout << "Num1 is : " << num1 << endl;
		cout << "Num2 is : " << num2 << endl;
		cout << "Dnum is : " << dnum << endl;
	}
};

class sample1 {
	int num1;
public:
	explicit sample1(int x = 0) : num1(x) {
		cout << "Ctor called for sample1" << endl;
	}

	~sample1() {
		cout << "dtor called for sample1" << endl;
	}

	void print() {
		cout << "Print func called from sample1" << endl;
		cout << "Num1 : " << num1 << endl;
	}
};

int main() {
	sample s{10, 20, 30.23};
	s.print();
	sample1 s1{100};
	s1.print();

	return 0;
}
