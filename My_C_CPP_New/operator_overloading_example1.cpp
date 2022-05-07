#include<iostream>
using namespace std;


class CA {
	int x;

public:
	/*single parameter constructor since we intilize the obj as 0*/
	CA(int a = 0) : x(a) {
		int y;
		cout << "Constructing one parameter constructor with x = " << x << endl;
		cout << "Enter decrement value" << endl;
		cin >> y;
		x = this->x - y;
		cout << "Value of x now is " << x << "\n";
	}

	/*overloaded ++ operator to make the object++ work*/
	CA& operator++(int) {
		++this->x;
		cout << "\nNow increamenting the vale of x = " << x << endl;
		return *this;

	}

	/*overloaded the < operator to make the comparison between the integer and object work*/
	bool operator < (int s)const {
		return this->x < s;
	}

	~CA() {
		cout << "Going to destruct" << endl;
	}
};

int main() {
	for (CA obj1 = 0; obj1 < 0; obj1++) {
		cout << "Loop working ";
	}
	return 0;
}
