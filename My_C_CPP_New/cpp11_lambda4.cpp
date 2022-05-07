/*lambda function*/
/*return from lambda function*/

#include <iostream>
using namespace std;

int main() {
	/*case #1 - compiler deduces return type */
	cout << [](int a) { return a * a; } (5) << endl;

	/* case #2 - explicit return type */
	cout << [](int a)->int { return a * a; } (5) << endl;

	return 0;
}

/*output
 * 25
 * 25
 */
