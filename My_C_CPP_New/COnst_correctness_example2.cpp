#include <iostream>
using namespace std;
/*An example of const correctness, const obj, const methods */

class CA {
	int a, b;
public:
	CA();
	CA(int);
	CA(int, int);
	CA(const CA&);
	~CA();
	void input();
	void print() const; /*const method - void print(const CA* const this)*/
	void print(); /*non-const method - void print(CA* const this)*/
};

/*Define function outside*/
CA::CA() : a(0), b(0) /* intialization list*/
{
	cout << "CA default const called" << endl;
}

CA::CA(int x) : a(x), b(0) {
	cout << "CA 1 arg const called" << endl;
}

CA::CA(int x, int y) : a(x), b(y) {
	cout << "CA 2 arg const called" << endl;
}

CA::~CA() {
	cout << "CA dest called" << endl;
}

CA::CA(const CA& x) : a(x.a), b(x.b) {
	cout << "CA copy const" << endl;
}

void CA::input() {
	cout << "Enter 2 nos" << endl;
	cin >> this->a >> this->b;
}

void CA::print() const {
	/*this->b = 10;*/
    cout << __FUNCDNAME__ << endl;
	cout << "const print called" << endl;
	cout << "a is : " << this->a << " b is : " << this->b << endl;
}

void CA::print() {
	a = 200;
	b = 100;
	cout << __FUNCDNAME__ << endl;
	cout << "Non const print called" << endl;
	cout << "a is : " << this->a << " b is : " << this->b << endl;
}

/*Consumner code*/
int main() {
	const CA obj1(20, 30);
	/*obj1.input();*/
	obj1.print();
	CA obj2(obj1);
	obj2.print();
	return 0;
}
