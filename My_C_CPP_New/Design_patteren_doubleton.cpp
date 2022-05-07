/*Multiton objcet creation*/
#include <iostream>
using namespace std;
#define MAX 5

class singleton_inst {
	static singleton_inst* sinst[MAX];
	static int count;
	singleton_inst() {
		cout << "singleton_inst ctor called" << endl;
	}

	~singleton_inst() {
		cout << "singleton_inst dest called" << endl;
	}

	singleton_inst(const singleton_inst& obj) {	}

	singleton_inst& operator=(const singleton_inst& obj) {
		return *this;
	}

public:
	static singleton_inst* get_inst() {
		if (count < MAX) {
			int i = 0;
			while (i < MAX) {
				if (sinst[i] == NULL) {
					sinst[i] = new singleton_inst;
					cout << "Allocation in location : " << i << endl;
					count++;
					return sinst[i];
				}
				i++;
			}
		}
		else {
			cout << "Index is : " << (count % MAX) << endl;
			return sinst[count++ % MAX];
		}
	}

	static void clear_ptr(int num) {
		if (num >= 0) {
			if (sinst[num] != NULL) {
				cout << "Deallocation in location : " << num << endl;
				delete sinst[num];
				sinst[num] = NULL;
				count--;
			}
		}
	}

	void print() {
		cout << "singleton_inst:: print func called" << endl;
	}
};

singleton_inst* singleton_inst::sinst[MAX] = { 0 };
int singleton_inst::count = 0;

int main() {
	singleton_inst::get_inst()->print();
	singleton_inst::get_inst()->print();
	singleton_inst::get_inst()->print();
	singleton_inst::get_inst()->print();
	singleton_inst::get_inst()->print();
	singleton_inst::clear_ptr(1);
	singleton_inst::get_inst()->print();
	singleton_inst::get_inst()->print();
	singleton_inst::get_inst()->print();
	return 0;
}