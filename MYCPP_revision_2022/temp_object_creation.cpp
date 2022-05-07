#include <iostream>
using namespace std;

class base {
	int num1;
public:
	base(int n = 0) : num1(n) {
		cout << "base const called" << endl;
	}

	~base() {
		cout << "base dest called" << endl;
	}
};

int main() {
	base();
	cout << "Size of base : " << sizeof(base) << endl;
	return 0;
}

/* output:-
base const called
base dest called
Size of base : 4
[Finished in 3.1s]
*/