/*
 * Why are returning refrence for copy assignment operator?
 * Why we should return refrence from copy assignment operator?
 * Ans:- TO support chaining assignment , but there is a point
 *
 * example:-
 * int a = 10, b, c;
 *
 * (b=c) = a;
 *
 * after this
 * b is having the value 10,
 * a is also having value 10, but c is having the garbage. its expected result .
 *
 * Now we are going to atchive this for class objects chain assignment using
 * returning object reference from the copy assignment operator.
 *
 */

#include <iostream>
using namespace std;

class Base {
	int _var;
public:
	Base(int v = 0) : _var(v) { cout << "Base const 1 arg called" << endl; }
	~Base() { cout << "Base dest called" << endl; }

	Base& operator=(const Base& obj) {
		if (this != &obj) {
			cout << "Base Assignment operator called" << endl;
			_var = obj._var;
		}
		return *this;
	}

	void print() {
		cout << "Base print func called" << endl;
		cout << "The _var is : " << _var << endl;
	}
};


int main() {
	Base b1(100), b2, b3;
	(b3 = b2) = b1;

	cout << "Obj b1 is printing : " << endl;
	b1.print();
	cout << "Obj b2 is printing : " << endl;
	b2.print();
	cout << "Obj b3 is printing : " << endl;
	b3.print();
	return 0;
}
