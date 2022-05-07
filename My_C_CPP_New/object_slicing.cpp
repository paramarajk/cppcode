#include <iostream>
using namespace std;

class base {
protected:
	int i;
public:
	base(int x = 0) : i(x) {
		cout << "base const" << endl;
	} 

	virtual void print() {
		cout << "Base: Value of i : " << i << endl;
	}

	~base() {
		cout << "base dest" << endl;
	}
};

class derived : public base {
	int j;
public:
	derived(int x, int y) : base(x), j(y) {
		cout << "derived const" << endl;
	}

	void print() {
		cout << "derived : Value of i : " << i << " , Value of j : " << j << endl;
	}

	~derived() {
		cout << "derived dest" << endl;
	}
};

//pass by value ---> lead to slicing of j value 
void somefunc_passbyval(base b) {
	b.print();
}

//it will resolve the object slicing
void somefunc_withref(base &b) {
	b.print();
}

void somefunc_withpointer(base *b) {
	b->print();
}

int main() {
	base b(10);
	derived d(20, 30);

	cout << endl << "with value----------------> " << endl;
	somefunc_passbyval(b); 
	somefunc_passbyval(d);  //--> lead to object slicing 

	cout << endl << "with refrence---------------> " << endl;
	somefunc_withref(b);    
	somefunc_withref(d);    //--> this will resolve object slicing

	cout << endl << "with pointer-------------> " << endl;
	somefunc_withpointer(&b);
	somefunc_withpointer(&d); //--> this will resolve object slicing

	return 0;
}