#include <iostream>
using namespace std;

class op_load {
	int x = 0;
public:
	op_load(int _x = 0) : x(_x) {
		cout << "op_load ctor" << endl;
	} 

	~op_load() {
		cout << "op_load dtor" << endl;
	}

	//op++ postincrement 
	op_load operator++(int) {
		cout << "op_load postincremet op++" << endl;
		op_load temp;
		temp.x = x++;
		return temp;
	}

	//< operator
	bool operator<(int s) const {
		cout << "op_load < operator" << endl;
		return x < s;
	}

	void print() {
		cout << "op_load print" << endl;
		cout << "X value : ---------------------> " << x << endl;
	}
};

int main() {
	for(op_load op = 0; op < 5; op++) {
		op.print();
	}

	return 0;
}
