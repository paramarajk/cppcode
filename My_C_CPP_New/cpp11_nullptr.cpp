/*nullptr*/
#include <iostream>
#include <cstddef>  //nullptr declared here
//#include <bits/stdc++.h>
using namespace std;

void func(int x) {
	cout << "func with int arg" << endl;
	cout << "x is : " << x << endl;
}

void func(char* c) {
	cout << "func with char * arg" << endl;
	if (c == NULL) {
		cout << "Received NULL for char*" << endl;
	}
	else {
		cout << "char * is not NULL" << endl;
	}
}

int main() {
	//func(NULL); // error: call of overloaded ‘func(NULL)’ is ambiguous
	func(nullptr);
	return 0;
}
