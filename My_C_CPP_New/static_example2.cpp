#include <iostream>
using namespace std;

class A {

public:
	int a;
	static int b;
};

int A::b = 0;

int main() {
	cout << "Sizof(A) is : " << sizeof(A) << endl;
	cout << "Value of B is : " << A::b << endl;
}

/*
output of the progran :
Sizof(A) is : 4
Value of B is : 0
*/

