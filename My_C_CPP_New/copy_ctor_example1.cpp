#include <iostream>
using namespace std;
/*An example of copy const, A const that takes single args,
which is an object of its own kind by refrence */

class CA {
	int a, b;
public:
	CA();
	CA(int);
	CA(int, int);
	CA(CA&);
	~CA();
	void input();
	void print();
};

/*Define function outside*/
CA::CA() {
	cout << "CA default const called" << endl;
	a = 0; b = 0;
}

CA::CA(int x) {
	cout << "CA 1 arg const called" << endl;
	a = x; b = 0;
}

CA::CA(int x, int y) {
	cout << "CA 2 arg const called" << endl;
	a = x; b = y;
}

CA::~CA() {
	cout << "CA dest called" << endl;
}

CA::CA(CA& x) {
	cout << "CA copy const" << endl;
	a = x.a;
	b = x.b;
}

void CA::input() {
	cout << "Enter 2 nos" << endl;
	cin >> this->a >> this->b;
}

void CA::print() {
	cout << "a is : " << this->a << " b is : " << this->b << endl;
}

/*Consumner code*/
int main() {
	CA obj1(20, 30);
	CA obj3(obj1);  /*Demands copy const*/

	CA obj2;     /*default const*/
	obj2 = obj1; /*assignment operator func called*/
	obj1.print();
	obj2.print();
	return 0;
}
