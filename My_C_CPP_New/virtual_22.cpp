#include <iostream>
using namespace std;

class Base {
public:
	void show() {
		cout << "Base : show func called" << endl;
	}
};

int main() {	
	Base* b = new Base;
	Base* b1; // error un intialized variables
	b->show();
	//b1->show();
	return 0;
}