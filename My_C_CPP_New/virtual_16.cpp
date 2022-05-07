#include <iostream>
using namespace std;

class base {
public:
	virtual void show() = 0;
};

class derived : public base {
public:
	void show() { cout << "In derived show" << endl; }
};


int main() {
	base* b = new derived();
	b->show();

	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/virtual_concept=>./pg7
In derived show
*/
