#include <iostream>
using namespace std;

void func1() {
	cout << "This is func1" << endl;
}

void func2(void (*fptr)()) {
	cout << "This is func2" << endl;
	fptr();
}


int add(int x, int y) {
	return x + y;
}

class sample {
public:
	
}

int main() {
	func2(func1);

	int (*fptradd)(int, int); //function pointer declaration
	fptradd=add;  //funtion pointer definition

	cout << "Sum of two int : " << fptradd(20, 30) << endl;

	return 0;
}