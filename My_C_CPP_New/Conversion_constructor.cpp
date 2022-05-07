#include <iostream>
using namespace std;

class A {

public:
	explicit A(const char* str) {
		cout << "const A" << endl;
	}

	explicit A(int x) {
		cout << "const int called A" << endl;
	}

	A(const A& obj) {
		cout << "copy const A" << endl;
	}
};

int main() {
	A obj1(10);
	//A obj2 = 10; //conversion constructor ..., throw error because having explicit const
	A obj3("hello"); 
	//A obj4 = "hello"; //conversion constructor ..., throw error because having explicit const
	return 0;
}
