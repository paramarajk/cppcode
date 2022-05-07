#include <iostream>
using namespace std;

class sample {
	int x;
public:
	sample() {
		cout << "sample const" << endl;
	}

	~sample() {
		cout << "sample dtor" << endl;
	}
};

int main() {
	cout << "SIZEOF(sample) : " << sizeof(sample) << endl;
	//Allocating memory normally
	sample s;

	//allocating memory using placement new
	char *memory = new (char[sizeof(sample)] * 2);
	cout << "SIZEOF(memory) : " << sizeof(memory) << endl;
	return 0;
}