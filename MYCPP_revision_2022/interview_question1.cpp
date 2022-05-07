/*Finding the no of instamces created in heap and stack*/
/*Using stack counter we can find*/

#include <iostream>
#include <stdlib.h>
using namespace std;

class sample {
	static int heap_count;
	static int static_count;
public:
	sample() {
		cout << "sample ctor called" << endl;
		static_count++;
	}

	~sample() {
		cout << "sample dest called" << endl;
		static_count--;
	}

	void* operator new(size_t size) {
		cout << "new operator called" << endl;
		heap_count++;
		static_count--;
		return malloc(size);
	}

	void operator delete(void * ptr) {
		cout << "delete operator called" << endl;
		heap_count--;
		static_count++;
		if (ptr != NULL) {
			free(ptr);
		}
	}

	static void print() {
		cout << "Static function called" << endl;
		cout << "Heap count is : " << heap_count << endl;
		cout << "Static count is : " << static_count << endl;
	}
};


int sample::heap_count = 0;
int sample::static_count = 0;

int main() {
	sample s1, s2, s3;
	sample *h1 = new sample();
	sample *h2 = new sample();
	sample::print();
	delete h2;
	sample::print();

	return 0;
}

