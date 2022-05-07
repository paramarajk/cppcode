#include<iostream>
using namespace std;

class Base
{
public:
	virtual void show() = 0;
};

void Base::show() {
	cout << "Show in Base" << endl;
}

int main(void)
{
	Base b;
	Base* bp;
	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/virtual_concept/geekfgeek=>g++ pg3.cpp -o pg3
pg3.cpp: In function 'int main()':
pg3.cpp:12:10: error: cannot declare variable 'b' to be of abstract type 'Base'
	 Base b;
		  ^
pg3.cpp:4:7: note:   because the following virtual functions are pure within 'Base':
 class Base
	   ^
pg3.cpp:7:18: note:     virtual void Base::show()
	 virtual void show() = 0;
*/
