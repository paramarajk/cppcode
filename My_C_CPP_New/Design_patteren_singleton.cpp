#include <iostream>
using namespace std;

class singleton_inst {
	static singleton_inst* sinst;
	singleton_inst() {
		cout << "singleton_inst ctor called" << endl;
	}

	singleton_inst(const singleton_inst& obj) {
		sinst = obj.sinst;
		cout << "copy ctor for : singleton_inst" << endl;
	}

	singleton_inst& operator=(const singleton_inst& obj) {
		if (this != &obj) {
			if (sinst != NULL) {
				delete sinst;
			}
			sinst = obj.sinst;
		}
		return *this;
	}

	~singleton_inst() {
		cout << "singleton_inst dest called" << endl;
	}

public:
	static void print() {
		cout << "Hello, this is print func from : singleton_inst class" << endl;
	}

	static singleton_inst* get_inst() {
		if (!sinst) {
			cout << "get_inst function from : singleton_inst" << endl;
			sinst = new singleton_inst;
		}
		return sinst;
	}

	void clear_ptr() {
		if (sinst != NULL) {
			delete sinst;
			sinst = NULL;
		}
	}
};

singleton_inst* singleton_inst::sinst = NULL;

int main() {
	singleton_inst::get_inst()->print();
	singleton_inst::get_inst()->print();
	singleton_inst::get_inst()->clear_ptr();

	return 0;
}
