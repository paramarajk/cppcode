#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> my(10, 5);
	cout << "1 " << my.size() << endl;
	cout << "1 " << my.capacity() << endl;
	my.push_back(100);
	my.push_back(100);
	cout << "2 " << my.size() << endl;
	cout << "2 " << my.capacity() << endl;
	my.pop_back();
	cout << "3 " << my.size() << endl;
	cout << "3 " << my.capacity() << endl;
	my.pop_back();
	my.pop_back();
	my.pop_back();
	my.pop_back();
	my.pop_back();
	cout << "4 " << my.size() << endl;
	cout << "4 " << my.capacity() << endl;
	return 0;
}