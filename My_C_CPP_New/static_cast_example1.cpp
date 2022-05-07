#include <iostream>
using namespace std;

class A {};
class B : public A {};
class C {};

int main() {
	A* a = new A;
	//C *c = static_cast<C *>(a); // its not related class , means its not inherited from the base class
	A* a1 = static_cast<A*>(new B); // upcast
	B* b = static_cast<B*>(a); //downcast
	
	return 0;
}
