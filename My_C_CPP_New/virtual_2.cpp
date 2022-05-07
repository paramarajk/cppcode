#include<iostream>
using namespace std;

class Base
{
public:
	virtual void show() { cout << " In Base \n"; }
};

class Derived : public Base
{
public:
	void show() { cout << "In Derived \n"; }
};

int main(void)
{
	Base* bp, b;
	Derived d;
	bp = &d;
	bp->show();
	bp = &b;
	bp->show();
	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/virtual_concept/geekfgeek=>./pg2
In Derived
In Base
*/
