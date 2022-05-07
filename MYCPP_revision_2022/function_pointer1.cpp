#include <iostream>
using namespace std;


class sample {
public:
	sample() {
		cout << "sample const" << endl;
	}

	void print() {
		cout << "sample print" << endl;
	}

	~sample() {
		cout << "sample dest" << endl;
	}
};

typedef void (sample::*fptr)(); //function pointer declaraion

class base {
	fptr fp;
public:
	base(fptr _fp = NULL) : fp(_fp) {
		cout << "base const" << endl;
	}

	void display(sample &obj) {
		(obj.*fp)(); //calling funtion using funtion pointer
	}

	~base() {
		cout << "base dest" << endl;
	}
};

int main() {
	sample obj;
	fptr fp = &sample::print;  //define funtion pointer
	base b(fp); //passing funtion pointer
	b.display(obj);
	
	return 0;	
}