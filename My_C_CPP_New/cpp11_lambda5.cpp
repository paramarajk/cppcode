/*lambda function*/
/* updating the global value*/

#include <iostream>
using namespace std;

int count;
int number = 1000;
int main() {
	/*passing 2 arguments with capture value &, number, that means except number all variables as refrence*/
	auto f = [&, number](int a) { ::count = a * 100; ::count += number; };
	f(5);
	cout << "count is : " << ::count << endl;
	return 0;
}

/*output
 * count is : 1500
 */
