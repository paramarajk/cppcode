#include <iostream>
using namespace std;

class test {
	int val;
public:
	test() {
		cout << val << endl;
		cout << "test: ctor" << endl;
	}
	void get_val() {
		//val = 100;
		cout << val << endl;
	}

	~test() {
		cout << "test: dtor" << endl;
	}
};

int main() {
	test t;
	t.get_val();
	cout << "Sizeof(test) : " << sizeof(test) << endl;
	cout << "Sizeof(t) : " << sizeof(t) << endl;
	return 0;
}