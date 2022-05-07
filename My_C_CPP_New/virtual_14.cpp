#include <iostream>
using namespace std;

class base {
public:
	virtual void show() = 0;
};

void base::show() {
	cout << "base show" << endl;
}

int main() {
	base b;

	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/virtual_concept=>g++ pg5.cpp -o pg5
pg5.cpp: In function 'int main()':
pg5.cpp:14:7: error: cannot declare variable 'b' to be of abstract type 'base'
  base b;
	   ^
pg5.cpp:4:7: note:   because the following virtual functions are pure within 'base':
 class base {
	   ^
pg5.cpp:9:6: note:      virtual void base::show()
 void base::show() {
	  ^
*/

