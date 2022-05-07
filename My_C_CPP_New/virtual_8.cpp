//Virtual Destructor
#include<iostream>
using namespace std;
class Base {
public:
	Base() { cout << "Constructor: Base" << endl; }
	virtual ~Base() { cout << "Destructor : Base" << endl; }
};
class Derived : public Base {
public:
	Derived() { cout << "Constructor: Derived" << endl; }
	~Derived() { cout << "Destructor : Derived" << endl; }
};
int main() {
	Base* Var = new Derived();
	delete Var;
	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/virtual_concept/geekfgeek=>g++ pg8.cpp -o pg8
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/virtual_concept/geekfgeek=>./pg8
Constructor: Base
Constructor: Derived
Destructor : Derived
Destructor : Base
*/
