#include <iostream>
using namespace std;

constexpr int func() {
	return 10;
}

int main() {
	int arr[2 + func()] = { 1, 1, 1, 1, 1, 1, 1 , 2, 2, 2, 2, 2};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << "Size of the array is : " << size << endl;

	//printing the array
	for (int i = 0; i < size; i++) {
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
}