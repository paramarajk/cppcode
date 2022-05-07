#include <iostream>
using namespace std;

class sample{
public:
	void operator() (const char* str) {
		cout << "The observed String is : ===>  " << str << endl;
	}
};

int main() {
	sample sobj;
	sobj("Hello, This is functor string...");
	return 0;
}