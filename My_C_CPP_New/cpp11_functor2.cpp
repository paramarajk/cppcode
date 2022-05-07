/* Functor means function object, The object works like a function
example : void func(int x) { };
while calling this function, func(a);

like the above statement, we are having class
class A { };
A a; this is the object for class A , it will act like function calling
a(10)*/

#include <iostream>
using namespace std;
class AddFunctor {
	int _num1, _num2;

public:

	AddFunctor(int n1 = 0, int n2 = 0) : _num1(n1), _num2(n2) {
		cout << "AddFunctor const called" << endl;
	}

	~AddFunctor() {
		cout << "AddFunctor dest called" << endl;
	}

	int operator() (int n1, int n2) {  // overloading () operator for achiving the functor concept
		_num1 = n1;
		_num2 = n2;
		return _num1 + _num2;
	}
};


int main() {
	AddFunctor af;
	cout << "AddFunctor result is : " << af(100, 200) << endl;
	return 0;
}

/*output
AddFunctor const called
AddFunctor result is : 300
AddFunctor dest called
*/
