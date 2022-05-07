#include <iostream>
using namespace std;

class op_load {
	int size;
	double *elem;
public:
	op_load(int _size = 0, double *_elem = NULL) : size(_size) {
		if(size != 0) {
			elem = new double[size];
			for (int i = 0; i < size; i++) {
				elem[i] = i + 1;
			}
		} else {
			elem = NULL;
		}
		cout << "op_load ctor" << endl;
	}

	~op_load() {
		cout << "op_load dest" << endl;
		if(elem != NULL) {
			delete [] elem;
			elem = NULL;
		}
	} 

	double& operator[] (int index) {
		if(index < size) {
			return elem[index];
		} else {
			cout << "index is out of range" << endl;
		}
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << "elem[" << i << "] : -> " << elem[i] << endl;
		}
	}
};


int main() {
	op_load op(5);
	op.print();
	double val = op[2];
	cout << "op[2] : -> " << val << endl;

	return 0;
}