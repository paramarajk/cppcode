#include <iostream>
using namespace std;


class static_class {
	static int num1;
	int num2;
public:
	static_class(int n = 0) : num2(n) {
		cout << "Ctor called for static_class" << endl;
	}

	~static_class() {
		cout << "Dtor called for static_class" << endl;
	}

	//from static function we can access only static variables
	static void static_print() {
		cout << "Static_print func called" << endl;
		cout << "Num1 is : " << num1 << endl;
		//calling non static member from static function 
		//getting error:
		//cout << "Num2 is : " << num2 << endl; //error: invalid use of member 'static_class::num2' in static member function
	}

	//from non static function we can call static variable also
	void non_static_print() {
		cout << "non_static_print func called" << endl;
		cout << "Num1 is : " << num1 << endl;
		cout << "Num2 is : " << num2 << endl;
	}
};

int static_class::num1 = 12;

int main() {

	static_class::static_print();

	static_class s(100);
	s.non_static_print();
	return 0;
}



/*output :-
Static_print func called
Num1 is : 12
Ctor called for static_class
non_static_print func called
Num1 is : 12
Num2 is : 100
Dtor called for static_class
[Finished in 2.4s]
*/