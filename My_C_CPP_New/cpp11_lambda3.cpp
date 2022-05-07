/*lambda functions*/
/* The (1) and (2) are equivalent, and produced the results, 20.*/
#include <iostream>
using namespace std;

int main() {
	//1st lambda functions
	cout << "1st lambda function" << endl;
	cout << [](int a, int b) {return a * b; } (4, 5) << endl;

	//2nd lambda function
	auto f = [](int a, int b) {return a * b; };
	cout << "2nd lambda function" << endl;
	cout << f(4, 5) << endl;
	return 0;
}

/*output
 * 1st lambda function
 * 20
 * 2nd lambda function
 * 20
 */
