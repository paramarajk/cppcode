/*lambda functions [](){} */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void assign(int& v) {
	static int n = 1; v = n++;
}

void print(int v) {
	cout << v << ' ';
}

int main() {
	vector<int> myvec(10);

	// output initial value of each element
	for_each(myvec.begin(), myvec.end(), print);
	cout << endl;

	// assign a value to each element of a vector
	for_each(myvec.begin(), myvec.end(), assign);

	// output updated value of each element
	for_each(myvec.begin(), myvec.end(), print);
	cout << endl;
	return 0;
}
