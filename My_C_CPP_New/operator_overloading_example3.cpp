#include <iostream>
using namespace std;

class op_load {
	int num1, num2;
public:
	/*ctor  & dtor */
	op_load(int n1 = 0, int n2 = 0) : num1(n1), num2(n2) {
		cout << "ctor called" << endl;
	}

	~op_load() {
		cout << "dtor called" << endl;
	}

	op_load(const op_load& obj) {
		cout << "copy ctor called" << endl;
		num1 = obj.num1;
		num2 = obj.num2;
	}

	/*+ operator overloading*/
	op_load operator+(op_load& obj) {
		op_load temp;
		temp.num1 = this->num1 + obj.num1;
		temp.num2 = this->num2 + obj.num2;
		cout << "operator+ called" << endl;
		return temp;
	}

	/*x++ post increment operator overloading*/
	op_load operator++(int) {
		op_load temp;
		temp.num1 = num1++;
		temp.num2 = num2++;
		cout << "operator++(int) called" << endl;
		return temp;
	}

	/*++x pre increment operator overloading*/
	op_load& operator++() {
		num1++;
		num2++;
		cout << "operator++ called" << endl;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const op_load& obj);
	friend istream& operator>>(istream& in, op_load& obj);

	/*print func*/
	void print() {
		cout << "Num1 is : " << num1 << endl;
		cout << "Num2 is : " << num2 << endl;
	}
};

ostream& operator<<(ostream& out, const op_load& obj) {
	out << "Num1 is : " << obj.num1 << endl;
	out << "Num2 is : " << obj.num2 << endl;
	return out;
}

istream& operator>>(istream& in, op_load& obj) {
	cout << "Enter num1 and num2 1 by 1" << endl;
	in >> obj.num1;
	in >> obj.num2;
	return in;
}

int main() {
	op_load op1(100, 200), op2(10, 20), op3;
	//op3 = op1 + op2;
	/*op3.print();
	op1.print();
	op2.print();*/
	cout << op2++;
	op2.print();
	//++op1;
	//op1.print();
	/*cin >> op2;
	cout << op2;*/
	return 0;
}
