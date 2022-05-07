#include <iostream>
using namespace std;

class sample {
	~sample() {
		cout << "sample dest called" << endl;
	}
public:
	sample() {
		cout << "sample const called" << endl;
	}
	
	void show() {
		cout << "sample show func called" << endl;
	}

	void clearptr() {
		delete this;
	}
};

int main() {
	//sample s; //'sample::~sample()' is private within this context
	sample *s = new sample();
	s->show();
	s->clearptr();
	return 0;
}