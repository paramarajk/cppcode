#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void print(int v) {
	cout << v << ' ';
}

void assign(int &v) {
	static int n = 1;
	v = n++;
}

int main() {
	vector<int> myvec(10);

	//printing the vector using foreach
	for_each(myvec.begin(), myvec.end(), print);
	cout << endl;

	//Assign the values for vector
	for_each(myvec.begin(), myvec.end(), assign);

	//Printing the updated values
	for_each(myvec.begin(), myvec.end(), print);
	cout << endl; 

	return 0;
}