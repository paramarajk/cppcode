/*Note that in the function-matching process, 
the compiler discriminate between const and non-const variables*/

#include <iostream>
using namespace std;

void func(const char* s) { cout << "const char *s" << endl; }
void func(char* s) { cout << "char *s" << endl; }

int main() {
	//const char *
	func("param");

	//char *
	char a[] = "hello";
	func(a);
	return 0;
}

/*output
 * const char *s
 */
