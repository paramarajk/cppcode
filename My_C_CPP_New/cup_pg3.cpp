/*Finding the no of instamces created in heap and stack*/
/*Using stack counter we can find*/

#include <iostream>
#include <stdlib.h>
using namespace std;

class sample {
	static int stack_count;
	static int heap_count;
public:
	sample() {
		cout << "sample const called" << endl;
		stack_count++;
	}

	~sample() {
		cout << "sample dest called" << endl;
		stack_count--;
	}

	void* operator new(size_t size) {
		cout << "New operator called" << endl;
		heap_count++;
		stack_count--;
		return malloc(size);
	}

	void operator delete(void* ptr) {
		cout << "Delete operator called" << endl;
		heap_count--;
		stack_count++;
		if (ptr != NULL)
			free(ptr);
	}

	static void print() {
		cout << "No of stack objects : " << stack_count << endl;
		cout << "No of heap objects : " << heap_count << endl;
	}
};

int sample::stack_count = 0;
int sample::heap_count = 0;

int main() {
	sample s1, s2, s3, s4;
	sample::print();
	sample* s1_p = new sample;
	sample* s2_p = new sample;
	sample::print();
	delete s1_p;
	sample::print();
	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/tricky_question/Interview_questions/careerup=>./pg3
sample const called
sample const called
sample const called
sample const called
No of stack objects : 4
No of heap objects : 0
New operator called
sample const called
New operator called
sample const called
No of stack objects : 4
No of heap objects : 2
sample dest called
Delete operator called
No of stack objects : 4
No of heap objects : 1
sample dest called
sample dest called
sample dest called
sample dest called
*/
