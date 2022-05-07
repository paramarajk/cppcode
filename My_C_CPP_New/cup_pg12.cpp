/* adobe-interview-questions
Given a variable, how can you find whether it was allocated from stack or from heap memory???*/

#include <iostream>
using namespace std;

class test {
	int num1;
	
public:
	test(int n = 0) : num1(n) {
		cout << "test const called" << endl;
	}

	~test() {
		cout << "test dest called" << endl;
	}

	void is_stack_heap() {
		num1 == NULL;
		if (num1 == 0)
			cout << "num1 is on the stack" << endl;
		else
			cout << "num1 is on heap" << endl;
	}
};

int main() {
	test t;
	t.is_stack_heap();

	return 0;
}
