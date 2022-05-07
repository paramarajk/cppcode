#include<iostream>
using namespace std;

class addfunctor {
	int num1, num2;
public:
	addfunctor(int x = 0, int y = 0) : num1(x), num2(y) {
		cout << "Ctor called for addfunctor" << endl;
	}

	~addfunctor() {
		cout << "dtor called for addfunctor" << endl;
	}

	int operator() (int n1, int n2) {
		num1 = n1;
		num2 = n2;
		return num1 + num2;
	}
};

int main() {
	addfunctor af;
	cout << "Adding two numbers using functor : " << af(100, 200) << endl;
	return 0;
}