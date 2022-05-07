#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int& func() {
	int a = 10;
	int& b = a;
	return b;
}

int main() {
	int a = 11;
	a = func();
	cout << "a : " << a << endl;
	return 0;
}