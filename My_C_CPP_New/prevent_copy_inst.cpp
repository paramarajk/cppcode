/*
How can you prevent object copy in C++?
There is a simple trick that we can apply in C++ class that is by making copy constructor and assignment operator private,
we can prevent copy or assignment of an object of a class.*/

#include <iostream>
using namespace std;

class sample {
	sample(const sample& obj) {
		cout << "sample copy const called" << endl;
	}

	sample& operator=(const sample& obj) {
		if (this != &obj) {
			cout << "sample Assignment operator called" << endl;
		}
		return *this;
	}
public:
	sample() {
		cout << "sample const called" << endl;
	}

	~sample() {
		cout << "sample dest called" << endl;
	}
};

int main() {
	sample s;
	//sample s1 = s; //This will through error
	sample s2;
	//s2 = s1; //This will through error
	return 0;
}

/*output
sample const called
sample const called
sample dest called
sample dest called
*/
