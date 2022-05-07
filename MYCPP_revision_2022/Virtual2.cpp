#include <iostream>
using namespace std;

class base {
public:
	virtual void show() = 0;
};

void base::show() {
	cout << "Base show func defined outside of class" << endl;
}

int main() {
	base *bp; //pointer can create for abstract calss
	//base b; //This will through error 
	return 0;
}