/*prevent stcak inst
sample s; //error
sample *s; -->success
*/
#include <iostream>
using namespace std;

class sample {
	~sample() {
		cout << "sample dest called" << endl;
	}
public:
	void display() {
		cout << "sample display func called" << endl;
	}

	sample() {
		cout << "sample const called" << endl;
	}

	void delete_func(sample *s) {
		delete s;
	}
};

int main() {
	//sample ss; /*lead to error*/
	sample* s = new sample;
	s->display();
	s->delete_func(s);
	return 0;
}

/*output:
sample display func called
*/
