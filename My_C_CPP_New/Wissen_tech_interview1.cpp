#include <iostream>
using namespace std;

class A {
	int num1;
protected:
	int num2;
public:
	int num3;

	A(int x = 100, int y = 200, int z = 300) : num1(x), num2(y), num3(z) {}
};

class B : private A {
public:
	B() {}
	void get() {
		cout << num2 << endl;
		cout << num3 << endl;
	}
};

int main() {
	B b;
	b.get();
	return 0;

}