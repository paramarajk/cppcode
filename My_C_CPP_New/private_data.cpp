#include <iostream>
using namespace std;

class sample {
	int a;  //its private data member
private:
protected:
public:
	sample(int _a = 0) : a(_a) { cout << "const called" << endl; }
	int get_data() {
		cout << "Tha value of a is : " << a << endl;
	}
};

class sample2 : sample {
	sample s;
public:
	sample2() { cout << "sample2 const called" << endl; }
	void set_data() {
		s.a = 100;
	}
};

int main() {
	sample2 s1;
	s1.set_data();
	sample s;
	s.a = 100;
	//s.get_data();

	return 0;
}
