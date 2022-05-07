#include <iostream>
using namespace std;

class Example {
public:
	int a, b, c;
	Example() { a = b = c = 1; cout << "ctor1" << endl; } //Constructor 1
	Example(int _a) { a = _a; b = c = 1; cout << "ctor2" << endl; } //Constructor 2
	Example(int _a, int _b) { a = _a; b = _b; c = 1; cout << "ctor3" << endl; } //Constructor 3
	Example(int _a, int _b, int _c) { a = _a; b = _b; c = _c; cout << "ctor4" << endl; } //Constructor 4
	void show() {
		cout << "a -> " << a << endl;
		cout << "b -> " << b << endl;
		cout << "c -> " << c << endl;
	}
};

int main() {
	Example* obj = new Example(1, 2, 4.3f);
	obj->show();
	return 0;
}
