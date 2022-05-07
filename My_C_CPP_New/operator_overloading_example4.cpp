/*operator overloading []*/
#include <iostream>
using namespace std;

class op_load {
	int size;
	double* elem;
public:
	op_load(int s = 0) : size(s), elem(NULL) {
		if (size != 0) {
			elem = new double[size];
			for (int i = 0; i < size; i++) {
				elem[i] = i + 1;
			}
		}
		cout << "ctor called" << endl;
	}

	~op_load() {
		if (elem != NULL) {
			delete[] elem;
			elem = NULL;
		}
		cout << "dtor called" << endl;
	}

	double& operator[](int index) {
		if (index < size) {
			return elem[index];
		}
		else {
			cout << "out of bound" << endl; 
		}
	}
};

int main() {
	op_load op(10);
	double val = op[3]; //object is behaving like array  //conversion operator
	op[2] = op[3];
	cout << "op[3] = " << val << endl;
	cout << "op[2] = " << op[2] << endl;
	return 0;
}
