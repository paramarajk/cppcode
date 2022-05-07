/*We are having only pure virtual func in base , no definition for that in derived*/
#include <iostream>
using namespace std;

class base {
public:
	virtual void show() = 0;
};

class derived : public base { };

int main() {
	derived q;
	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/virtual_concept/geekfgeek=>g++ pg4.cpp -o pg4
pg4.cpp: In function 'int main()':
pg4.cpp:12:10: error: cannot declare variable 'q' to be of abstract type 'derived'
  derived q;
		  ^
pg4.cpp:9:7: note:   because the following virtual functions are pure within 'derived':
 class derived : public base { };
	   ^
pg4.cpp:6:16: note:     virtual void base::show()
   virtual void show() = 0;
				^
*/
