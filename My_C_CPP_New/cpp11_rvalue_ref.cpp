#include<iostream>
using namespace std;

//const lvalue ref -> will accept lvalue and rvaue also
void print_const_lrvalue_ref(const int& ref) {
	cout << "print_const_lrvalue_ref : " << ref << endl;
}

//rvalue ref
void print_rvalue_ref(int&& ref) {
	cout << "print_rvalue_ref : " << ref << endl;
}

int main() {
	int val = 100; //var is lvalue, 100 is rvalue
	print_const_lrvalue_ref(val);
	print_const_lrvalue_ref(200);

	print_rvalue_ref(300);
	//print_rvalue_ref(val); //error: cannot bind rvalue reference of type 'int&&' to lvalue of type 'int'
	return 0;
}