#include <iostream>
using namespace std;

void func1(int a, int b) {
	cout << "func1 called" << endl;
	cout << a + b << endl;
}

void func2(float a, float b) {
	cout << "func2 called" << endl;
	cout << a + b << endl;
}

template <typename T>
void func3(T a, T b) {
	cout << "func3 called" << endl;
	cout << a + b << endl;
}


int main() {
	func1(10, 20);
	func2(30.5, 20.5);
	func3(100, 200);
	func3(10.5, 10.5);
}

