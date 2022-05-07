#include <iostream>
using namespace std;

class Test {
	int x;
	static int y;
	friend void getx();
};

int Test::y = 1000;

void getx() {
	Test t;
	t.x = 100;
	cout << t.x << endl;
	cout << Test::y << endl;
}

int main() {
	getx();
	return 0;
}