#include<iostream>
using namespace std;

class BaseA {
	int i;
public:
	BaseA(int ii) : i(ii) { 
		cout << "conversion const called" << endl; 
	} //conversion constructor

	void show() {
		cout << "Value of i is " << i << endl;
	}
};


class BaseB {
	int x;
public:
	BaseB(int xx) : x(xx) { }
	operator BaseA() const { 
		cout << "converson operator called" << endl; return BaseA(x); 
	} //conversion operator
};

void func(BaseA a) {
	a.show();
}

int main() {
	BaseB b(10);
	func(b); //it will call conversion operator for assigning the BaseB to BaseA
	func(20); //it will call conversion constructor for assigning int 20 to BaseA
	return 0;
}
