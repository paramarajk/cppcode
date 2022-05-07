#include <iostream>
using namespace std;

class CA {
public:
	void print() const { 
		cout << "CA print called" << endl; 
	}
};

typedef void(CA::* CFP)() const; // function pointer declarations

class Adapter {
private:
	CFP fp;
public:
	Adapter(CFP ff) : fp(ff) { cout << "Adapter const called" << endl; }
	void print(CA& x) {
		(x.*fp)();  // calling the print function of CA , using function pointer with obj
	}

	void operator()(CA& x) {  //Functor, function operator overload concept
		(x.*fp)(); // calling the print function of CA like function (adapter object act like a function,
					//that is called functor in c++, -> object behaves like a function calling
	}
};

/*Consumer code*/
int main() {
	CA obj1;
	CFP ff1 = &CA::print; // function pointer intializations
	Adapter adapt(ff1);
	adapt.print(obj1);
	adapt(obj1);         //adapt.operator()(obj1);
	return 0;
}
