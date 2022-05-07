/* created refrence of base and assign the object of derived*/
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
	derived d;
	//Using refrence
	base& br = d;
	br.show();

	//Using pointer
	base *bp = &d;
	bp->show();

	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/virtual_concept/geekfgeek=>./pg5
In derived show
*/
