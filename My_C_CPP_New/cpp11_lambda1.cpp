/*lambda functions [](){} */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//for_each with lambda function
int main() {
	vector<int> myvec(10);

	// output initial value of each element
	for_each(myvec.begin(), myvec.end(), [](int v) {cout << v << ' '; });
	cout << endl;

	// assign a value to each element of a vector
	for_each(myvec.begin(), myvec.end(), [](int& v) {static int n = 1; v = n++; });

	// output updated value of each element
	for_each(myvec.begin(), myvec.end(), [](int v) {cout << v << ' '; });
	cout << endl;
	return 0;
}

/*output:
 * 0 0 0 0 0 0 0 0 0 0
 * 1 2 3 4 5 6 7 8 9 10
 */
