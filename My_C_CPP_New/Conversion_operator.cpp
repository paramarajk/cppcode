#include <iostream>
using namespace std;


class CA {
	int a, b;
public:
	CA(int = 0, int = 0);
	operator int();
};

CA::CA(int x, int y) : a(x), b(y) { }

CA::operator int() {
	cout << "operator int () called" << endl;
	return a + b;
}

/*Consumer code*/
int main() {
	CA obj1(10, 20);
	//approch 1
	int x;
	x = obj1; // (or) x = obj1 // compile-> x = obj1.operator int ();
	cout << "X = " << x << endl;
	cout << "----------------------------" << endl;
	/*approch 2*/
	cout << obj1 << endl; /* cout << obj1.operator int () << endl;*/
	return 0;
}
