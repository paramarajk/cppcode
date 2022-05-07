#include <iostream>
using namespace std;

class CA {
	int a, b;
	/*Anywhere inside the class
	  friend void operator>>(istream& input, CA &x);
	  friend void operator<<(ostream& output, CA &x); // this is for void problem*/

	friend istream& operator>>(istream& input, CA& x);
	friend ostream& operator<<(ostream& output, CA& x);
};

/*global function*/
istream& operator>>(istream& input, CA& x) {
	cout << "operator >> called" << endl;
	cout << "enter 2 nos" << endl;
	input >> x.a >> x.b;
	return input;
}

ostream& operator<<(ostream& output, CA& x) {
	cout << "operator << called" << endl;
	output << "a = " << x.a << " b = " << x.b << endl;
	return output;
}

int main() {
	CA obj1;
	/*cin >> obj1;*/ /*operator >> (cin, obj1);*/
	/*cout << obj1;*/ /*operator << (cin, obj1);*/
	CA obj2;
	cin >> obj1 >> obj2;  /*(operator>>(operator>>(cin, obj1), obj2);---> (operator>>(void, obj2); 
						  this void is problem for obj2 if we are using void*/
	cout << obj1 << obj2;
	return 0;
}
