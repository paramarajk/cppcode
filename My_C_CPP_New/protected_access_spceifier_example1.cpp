#include <iostream>
using namespace std;

class base {
protected:
	int _num1, _num2;
public:
	base(int _n1, int _n2) : _num1(_n1), _num2(_n2) {}
	~base() {}
};

class derived1 : public base {
	int _num3;
public:
	derived1(int _n1, int _n2, int _n3) : base(_n1, _n2), _num3(_n3) {}
	void print() {
		cout << "_num1 : " << _num1 << endl;
		cout << "_num2 : " << _num2 << endl;
		cout << "_num3 : " << _num3 << endl;
	}
	~derived1() {}
};

class derived2 : public base {
public:
	derived2(int _n1, int _n2) : base(_n1, _n2) {}
	void print() {
		cout <<  "_num1 : " << _num1 << endl;
		cout << "_num2 : " << _num2 << endl;
	}
	~derived2() {}
};

int main() {
	derived1 d1(3, 4, 5);
	d1.print();
	derived2 d2(5, 4);
	d2.print();
	return 0;
}
