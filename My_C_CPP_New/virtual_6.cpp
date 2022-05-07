/*Can a constructor be virtual? Will the following program compile? */
#include <iostream>
using namespace std;

class base {
public:
	virtual base() { }
};

int main() {
	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/virtual_concept/geekfgeek=>g++ pg6.cpp -o pg6
pg6.cpp:7:16: error: constructors cannot be declared virtual [-fpermissive]
   virtual base() { }
				^
*/
