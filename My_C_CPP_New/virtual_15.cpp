#include <iostream>
using namespace std;

class base {
	virtual void show() = 0;
};

class derived : public base {
public:
	void show() {
		cout << "derived show" << endl;
	}
};

int main() {
	base* b = new derived;
	b->show(); //if we uncomment, will get error : error: 'virtual void base::show()' is private how it will work
	cout << "sizeof(base) is :" << sizeof(base) << endl;
	cout << "sizeof(derived) is :" << sizeof(derived) << endl;

	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/virtual_concept=>./pg6
sizeof(base) is :4
sizeof(derived) is :4
*/
