#include <iostream>
using namespace std;


class static_class {
	static int count;
	int num1;

public:
	static_class(int x = 0) : num1(x) {
		cout << "static_class const called" << endl;
	}


	~static_class() {
		cout << "static_class dest called" << endl;
	}


	static void static_class_print() {
		cout << "static_class_print func called" << endl;
		cout << "count is : " << count << endl;
		//cout << num1 << endl; //non static member not able to access from static function
	}

	void static_class_display() {
		cout << count << endl;
	}
};

int static_class::count = 1000;

int main() {
	static_class::static_class_print();
	static_class s;
	s.static_class_display();
	return 0;
}