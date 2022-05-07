#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
	int i;
	double j;
	string s;
	cout << typeid(i).name() << endl;
	cout << typeid(j).name() << endl;
	cout << typeid(s).name() << endl;

	return 0;
}
