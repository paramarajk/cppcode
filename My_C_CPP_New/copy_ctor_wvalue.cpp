/*in C++, a copy constructor doesn.t support pass by value but pass by reference only.
It cannot accept object parameter by value and it should always receive it as a reference.
An error, .Illegal copy constructor. will be thrown if we receive object by value.*/

/*This program will through like :
copy_const_wvalue.cpp:18:46: error: invalid constructor; you probably meant 'copy_const_value (const copy_const_value&)'
   copy_const_value(const copy_const_value obj) {
											   ^
*/

#include <iostream>
using namespace std;

class copy_const_value {
public:
	copy_const_value() {
		cout << "copy_const_value const called" << endl;
	}

	~copy_const_value() {
		cout << "copy_const_value dest called" << endl;
	}

	copy_const_value(const copy_const_value obj) {
		cout << "copy_const_value copy const called" << endl;
	}
};

int main() {
	copy_const_value ccv;
	copy_const_value ccv1 = ccv;

	return 0;
}
