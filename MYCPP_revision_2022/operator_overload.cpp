#include <iostream>
using namespace std;

class op_load {
	int num1, num2;
public:
	//ctor & dtor
	op_load(int n1 = 0, int n2 = 0) : num1(n1), num2(n2) {
		cout << "op_load const" << endl;
	}

	~op_load() {
		cout << "op_load dest" << endl;
	}

	//copy ctor
	op_load(const op_load& obj) {
		cout << "op_load copy ctor called" << endl;
		num1 = obj.num1;
		num2 = obj.num2;
	}

	//+ operator ooverloading
	op_load operator+(op_load &obj) {
		cout << "+ operator" << endl;
		op_load temp;
		temp.num1 = num1 + obj.num1;
		temp.num2 = num2 + obj.num2;
		return temp;
	}

	//num1++ post increment operator
	op_load operator++(int) {
		cout << "postincrement operator" << endl;
		op_load temp;
		temp.num1 = num1++;
		temp.num2 = num2++;
		return temp;
	} 

	//++num1 preinrement operator
	op_load& operator++() {
		cout << "preincrement operator" << endl;
		num1++;
		num2++;
		return *this;
	}

	void print() {
		cout << "op_load print" << endl;
		cout << "Num1 : " << num1 << endl;
		cout << "Num2 : " << num2 << endl; 
	}

	//<< & >> operator 
	friend ostream& operator<<(ostream &out, const op_load &obj);
	friend istream& operator>>(istream &in, op_load &obj);


	//< operator
	bool operator< (int s) {
		cout << "op_load < operator" << endl;
		return num1 < s;
	}
};


ostream& operator<<(ostream &out, const op_load &obj) {
	cout << "op_load operator<<" << endl;
	out << "operatror << : Num1 : " << obj.num1 << endl;
	out << "operatror << : Num2 : " << obj.num2 << endl;
	return out;
}

istream& operator>>(istream &in, op_load &obj) {
	cout << "Enter num1 and num2 1 by 1" << endl;
	in >> obj.num1;
	in >> obj.num2;
	return in;
}



int main() {
	op_load op1(10, 20);
	op_load op2(30, 40);
	op2++;
	op2.print();
	op_load op3 = op1 + op2;
	op3.print();
	cout << op2++;
	op2.print();
	cout << ++op2;

	bool res = op1 < 50;
	cout << "return value of op1 < 2 : " << res << endl;
	
	return 0;
}