/*functor is used to make object bhaves like function*/

#include <iostream>
using namespace std;

class sample {
public:
	void operator() (const char* _buf) {
		cout << "Functor sample : " << _buf << endl;
	}
};

int main() {
	sample sobj;
	sobj("Hello Functor of sample class");
	return 0;
}
