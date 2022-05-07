#include <iostream>
using namespace std;

template <typename T, typename U>
auto func(T a, U b) -> decltype(a + b) {
	return a + b;
}

int main() {
	cout << "Dectype func : --> " << func(2.6, 3) << endl;
	return 0;
}