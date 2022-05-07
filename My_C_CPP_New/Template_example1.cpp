#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T = double> 
class CA   // 'double' is the default type
{
private:
	T a, b;
public:
	CA(T);
	CA(T, T);
	void sum();
	~CA();
};

template <typename T> 
CA<T>::CA(T x) :a(x), b(x) 
{
	cout << "CA<" << typeid(T).name() << "> one arg. constructor" << endl;
}

template <typename T> 
CA<T>::CA(T x, T y) : a(x), b(y)
{
	cout << "CA<" << typeid(T).name() << "> two arg. constructor" << endl;
}

template <typename T> 
void CA<T>::sum()
{
	cout << "CA<" << typeid(T).name() << "> sum = " << a + b << endl;
}

template <typename T> 
CA<T>::~CA()
{
	cout << "CA<" << typeid(T).name() << "> destructor" << endl;
}

/*Specialize the method 'sum' of the generic class for CHAR type*/
template<>
void CA<char>::sum() {
	cout << "cannot add char" << endl;
}

//---------consumer ----------------
int main()
{
	CA<int> obj1(10, 20);
	obj1.sum();
	CA<float> obj2(34.12f, 89.54f);
	obj2.sum();
	CA<> obj3(67.98, 87.45);  //CA<double> obj3(67.98, 87.45);
	obj3.sum();
	/******************************************/
	CA<char> obj4('t', 'e');
	obj4.sum();
	return 0;
}
