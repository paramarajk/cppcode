#include <iostream>
using namespace std;

class base {
	int num1;
	static int num2;
public:
	friend int main();
};

int base::num2 = 10;

int main() {
	cout << "SIZEOF(BASE) : " << sizeof(base) << endl;  //it will provide size 4 for non static variable : num1
	cout << "Value of num2 is : " << base::num2 << endl;
	return 0;
}

/* Output:-
SIZEOF(BASE) : 4
Value of num2 is : 10
[Finished in 16.8s]
*/