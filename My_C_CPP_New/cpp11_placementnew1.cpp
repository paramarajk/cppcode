#include <iostream>
using namespace std;

class sample {
	int num1, num2;
public:
	sample(int _n1 = 10, int _n2 = 20) : num1(_n1), num2(_n2) { cout << "ctor called" << endl; }
	~sample() { cout << "dtor called" << endl; }
	void print() {
		cout << "num1 is : " << num1 << endl;
		cout << "num2 is : " << num2 << endl;
	}
};

int main() {
	//allocating pool of memory
	char* buf = new char[(sizeof(sample) * 10)];

	//placement new
	//new (address) type(intializer)
	{
		sample* s1 = new (buf) sample();
		s1->print();
		s1->~sample();
	}
	{
		sample* s2 = new (buf) sample(100, 200);
		s2->print();
		s2->~sample();
	}
	return 0;
}
