#include <iostream>
using namespace std;

class Exception {};

void func(int x) {
	try {
		if (x == 5)
			throw Exception();
		else
			cout << x << endl;
	}
	//If not handling the exception properly, will abort it Abs like : res1 else Ans :res2
	catch (...) {
		cout << "Class Exception...." << endl;
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		func(i);
	}
	cout << "Done" << endl;
	return 0;
}

/*
res1:
0
1
2
3
4
Aborted

res2:
0
1
2
3
4
Class Exception....
6
7
8
9
Done
*/