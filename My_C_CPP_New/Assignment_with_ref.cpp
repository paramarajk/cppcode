#include <iostream>

using namespace std;

class assign_ref {
	int _num1, _num2, _num3;

public:

	assign_ref(int num1 = 0, int num2 = 0, int num3 = 0) : _num1(num1), _num2(num2), _num3(num3) {
		cout << "assign_ref const called" << endl;
	}

	~assign_ref() {
		cout << "assign_ref dest called" << endl;
	}

	// here if we are not returning ref , it copy wont work
	//(A2 = A1) = A;
	// A will copy to A2 , A and A2 should have same values with returning ref
	assign_ref& operator=(const assign_ref& obj) {
		if (this != &obj) {
			_num1 = obj._num1;
			_num2 = obj._num2;
			_num3 = obj._num3;
			cout << "assign_ref assignment operator called" << endl;
		}
		return *this;
	}

	void print() {
		cout << "print func called" << endl;
		cout << "Num1 is : " << _num1 << endl;
		cout << "Num2 is : " << _num2 << endl;
		cout << "Num3 is : " << _num3 << endl;
	}
};


int main() {
	assign_ref a(10, 20, 30);
	assign_ref a1;
	assign_ref a2;

	cout << "A" << endl;
	a.print();
	cout << "A1" << endl;
	a1.print();
	cout << "A2" << endl;
	a2.print();
	(a2 = a1) = a;
	cout << "A" << endl;
	a.print();
	cout << "A1" << endl;
	a1.print();
	cout << "A2" << endl;
	a2.print();

	return 0;
}

/*output :
assign_ref const called
assign_ref const called
assign_ref const called
A
print func called
Num1 is : 10
Num2 is : 20
Num3 is : 30
A1
print func called
Num1 is : 0
Num2 is : 0
Num3 is : 0
A2
print func called
Num1 is : 0
Num2 is : 0
Num3 is : 0
assign_ref assignment operator called
assign_ref assignment operator called
A
print func called
Num1 is : 10
Num2 is : 20
Num3 is : 30
A1
print func called
Num1 is : 0
Num2 is : 0
Num3 is : 0
A2
print func called
Num1 is : 10
Num2 is : 20
Num3 is : 30
assign_ref dest called
assign_ref dest called
assign_ref dest called
*/
