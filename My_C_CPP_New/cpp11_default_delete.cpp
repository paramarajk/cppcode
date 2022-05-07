/*default & delete specifiers*/

#include <iostream>
using namespace std;

class sample {
public:
	sample(int num) {}
	sample() = default; //We can force the compiler make the one for us by using default specifier: 	
};

class test {
public:
	test(int a = 0) {
		cout << "int arg ctor called" << endl;
		cout << "A is : " << a << endl;
	}

	/*stoping the copy and assignment behaviors */
	test(const test& obj) = delete;
	test& operator=(const test& obj) = delete;
};

int main() {
	sample s; //compiler will generate default ctor for sample class

	cout << "delete keyword" << endl;
	test t(10);
	//test t1(t); //deleted function ‘test::test(const test&)’
	test t2;
	//t2 = t1; //error: deleted function ‘test& test::operator=(const test&)’
	return 0;
}
