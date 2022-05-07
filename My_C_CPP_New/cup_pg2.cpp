/* bloomberg-lp-interview-questions
How do you keep track of how many objects in given class exist*/

/*We can achive by using static counter*/

#include <iostream>
using namespace std;

class sample {
	static int count;
public:
	sample() {
		count++;
	}

	static void print() {
		cout << "No of objects created : " << count << endl;
	}

	~sample() {
		count--;
	}
};

int sample::count = 0;

int main() {
	sample s1, s2, s3, s4, s5, s6, s7;
	sample::print();
	sample* s = new sample;
	sample::print();
	delete s;
	sample::print();
	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/tricky_question/Interview_questions/careerup=>./pg2
No of objects created : 7
No of objects created : 8
*/
