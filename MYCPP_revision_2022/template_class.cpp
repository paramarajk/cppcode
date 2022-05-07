#include <iostream>
using namespace std;

template <typename T = double> 
class A {
	T a, b;
public:
	A(T);
	A(T, T);
	void sum();
	~A();
};

template <typename T>
A<T>::A(T x) : a(x), b(x) {
	cout << "A class ctor called with 1 arg" << endl;
}

template <typename T> 
A<T>::A(T x, T y) : a(x), b(y) {
	cout << "A class ctor called with 2 arg" << endl;
}

template <typename T>
A<T>::~A() {
	cout << "A class Dest called" << endl;
}

template <typename T>
void A<T>::sum() {
	cout << "Sum func called" << endl;
	cout << "Sum of two variables : " << a + b << endl;
}

template <>
void A<char>::sum() {
	cout << "spealized method sum with char type called" << endl;
	cout << "cannot add char" << endl;
}

int main() {
	A<int> a_obj(10, 20);
	a_obj.sum();
	A<int> a1_obj(30);
	a1_obj.sum();

	//default type double
	A<> a2_obj(20.0, 30.3);
	a2_obj.sum();

	A<char> a3_obj('a', 'b');
	a3_obj.sum();

	return 0;
}