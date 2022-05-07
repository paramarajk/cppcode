/*constexpr  : it will allow to run the func code at compile time ,
the we can set the size of static array based on return type of func*/

#include <iostream>
using namespace std;

constexpr int func() {
	return 7;
}

void print(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}
int main() {
	int arr[10 + func()] = { 0 };  //array size will set at compile time , because its static array.
	int size = (sizeof(arr) / sizeof(arr[0]));
	print(arr, size);
	return 0;
}
