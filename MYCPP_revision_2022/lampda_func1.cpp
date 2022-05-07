#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void foo() { cout << "Calling foo func" << endl; }
void bar() { cout << "Calling bar func" << endl; }


int main() {
	vector<int> myvec(10);

	//Printing the vector using lambda function
	for_each(myvec.begin(), myvec.end(), [] (int v) {cout << v << ' ';} );
	cout << endl;

	//Assign values for vector using lambda function
	for_each(myvec.begin(), myvec.end(), [] (int &v) {static int n = 1; v = n++; } );	

	//Printing the vector using lambda function
	for_each(myvec.begin(), myvec.end(), [] (int v) {cout << v << ' ';} );
	cout << endl;

	//lambda function defined here
	auto f = [] () {
		foo();
		bar();
	};

	//calling lambda function
	f();

	//below 2 lambda functions are same
	//func1
	cout << "First lambda function" << endl;
	cout << [] (int a, int b) {return a * b; } (10, 20) << endl;

	//func2
	cout << "second lambda function" << endl;
	auto f1 = [] (int a, int b) { return a * b; };
	cout << f1(10, 20) << endl;

	//Retrun type:-
	cout << "implicit return type" << endl;
	cout << [] (int a, int b) { return a + b; } (10, 20) << endl;

	cout << "explicit return type" << endl;
	cout << [] (double a, double b)->double {return a + b; } (10.1, 20.3) << endl;

	return 0;
}