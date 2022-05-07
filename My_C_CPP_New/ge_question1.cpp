#include <iostream>
#include <exception>
using namespace std;

class base { 
	virtual void dummy() {
	} 
};

class derived : public base {
	int a; 
};

int main() {
	try {
		base* pba = new derived;
		base* pbb = new base;
		
		derived *pd = dynamic_cast<derived*> (pba);
		if (pd == nullptr) {
			cout << "Null pointer on first type cast" << endl;
		}

		pd = dynamic_cast<derived*> (pbb);
		if (pd == nullptr) {
			cout << "Null pointer on second type_cast" << endl;
		}
	}

	catch (exception & e) {
		cout << "Exception : " << e.what() << endl;
	}

	catch (...) {
		cout << "Exception is unknown" << endl;
	}
	return 0;
}