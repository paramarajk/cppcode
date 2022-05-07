/*How ifdef is work*/

#include <iostream>
using namespace std;

#define SET 0
#undef SET

class sample {
public:
	void print_ifdef() {
#ifdef SET
		cout << "SET is presented" << endl;;
#else
		cout << "SET is not presented" << endl;
#endif

	}
};

int main() {
	sample s;
	s.print_ifdef();
}

/*output:
SET is not presented
*/
