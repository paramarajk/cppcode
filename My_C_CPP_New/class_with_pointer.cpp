#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string.h>

using namespace std;

class sample {
	char* ptr;
	int size;

public:

	sample(const char* str = NULL) : size(strlen(str)) {
		//cout << strlen(str) << endl;
		ptr = new char[size+1];
		strcpy(ptr, str);
		cout << "sample const called" << endl;
	}

	void get_data_sample() {
		cout << ptr << endl;
	}

	~sample() {
		//cout << "debug1" << endl;
		if (ptr != NULL) {
			delete[] ptr;
			ptr = NULL;
			cout << "Dest called" << endl;
		}
		//cout << "debug2" << endl;
		
	}
};

int main() {

	sample s("param");
	s.get_data_sample();
	return 0;
}
