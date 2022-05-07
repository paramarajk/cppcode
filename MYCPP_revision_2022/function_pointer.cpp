#include <iostream>
using namespace std;

class function_pointer {
public:
	void print() {
		cout << "function_pointer print" << endl;
	}
};

//with typedef
int main() {
	function_pointer f;
	typedef void (function_pointer::*fptr)();
	fptr fp;	
	fp = &function_pointer::print;
	(f.*fp)();

	return 0;
}

//without typedef
/*int main() {
	function_pointer f;
	void (function_pointer::*fptr)();
	fptr = &function_pointer::print;
	(f.*fptr)();

	return 0;
}*/