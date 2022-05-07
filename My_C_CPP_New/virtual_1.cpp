#include <iostream>
using namespace std;

class base {
public:
	virtual void show() { 
		cout << "In base show" << endl; 
	}
};

class derived : public base {
public:
	void show() { 
		cout << "In derived show" << endl; 
	}
};

int main() {
	cout << "With pointer ------>" << endl;
	base* bp = new derived;
	bp->show();

    cout << "with refrence for pointer ----->" << endl;
	base& br = *bp;
	br.show();

    cout << "With refrence ---->" << endl;
	derived d1;
    base &b1 = d1;
    b1.show();

	return 0;
}

/*
output : 
In derived show
In derived show
*/

