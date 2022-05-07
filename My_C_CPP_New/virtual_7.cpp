/*Can a destructor be virtual? Will the following program compile? */

#include <iostream>
using namespace std;

class base {
public:
	virtual ~base() {}
};

int main() {
	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/virtual_concept/geekfgeek=>g++ pg7.cpp -o pg7
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/virtual_concept/geekfgeek=>./pg7

Note : it will compile , wont create any problem*/

