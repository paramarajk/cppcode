//Function_overloading
#include <iostream>
using namespace std;

class sample {
	int a, b;
	double c, d;
public:
	void func(int a = 0, int b = 0) {
		cout << "Func with two integer called" << endl;
		cout << "A : " << a << endl;
		cout << "B : " << b << endl;
	}

	void func(double c = 0.1, double d = 0.2) {
		cout << "Func with two double called" << endl;
		cout << "C : " << c << endl;
		cout << "D : " << d << endl;
	}
};

int main() {
	sample s;
	s.func(10, 20);
	s.func(10.2, 20.3);
	//s.func();
}