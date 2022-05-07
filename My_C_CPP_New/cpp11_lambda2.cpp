/*lambda functions [](){}*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void foo() { cout << "called foo() func" << endl; }
void bar() { cout << "called bar() func" << endl; }

int main() {
	//lambda function defining here
	auto f = []() {
		foo();
		bar();
	};
	//lambda function calling
	f();

	//2nd lambda function
	vector<int> myvec(5, 99);
	for_each(myvec.begin(), myvec.end(), [](int v) {cout << v << ' '; });
	cout << endl;

	return 0;
}

/*output :
 * called foo() func
 * called bar() func
 * 99 99 99 99 99
 */
