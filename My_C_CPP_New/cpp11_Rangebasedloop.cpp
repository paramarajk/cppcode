#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = { 0, 1, 2, 3, 4, 5 };
	for ( auto i : v )
		cout << i << ' ';
	cout << endl;

	/*auto for iterator*/
	/*for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;*/

	return 0;
}
