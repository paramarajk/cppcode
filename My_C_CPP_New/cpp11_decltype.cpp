#include <iostream>
using namespace std;

template <typename T, typename U>
auto func(T a, U b) -> decltype(a + b) {
	return a + b;
}

int main() {
	cout << func(2.6, 2) << endl;
	return 0;
}
