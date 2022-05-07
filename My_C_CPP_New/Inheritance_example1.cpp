#include<iostream>
using namespace std;
/*An example on inheritance and the role of 'public' access specifier.*/

class CA {
private:
	int a, b;
public:
	void input(int x, int y)
	{
		cout << "CA-input, enter 2 nos" << endl;
		//cin >> a >> b;
		a = x;
		b = y;
	}
	void print()
	{
		cout << "CA-print, a = " << a << ",b=" << b << endl;
	}
};
/********************/
class CB :public CA
{
private:
	int a, b;

public:
	/*void CA::input() {}
	  void CA::print() {}*/
	void input(int x, int y)
	{
		cout << "CB-input, enter 2 nos" << endl;
		//cin >> a >> b;
		a = x;
		b = y;
	}
	void print()
	{
		cout << "CB-print, a = " << a << ",b=" << b << endl;
	}
};
/******consumer code************/
int main()
{
	cout << "size of CB " << sizeof(CB) << endl; /*CA data members + CB data members*/
	CB obj1;

	obj1.CA::input(10, 20);
	obj1.CB::input(30, 40);
	obj1.CA::print();
	obj1.CB::print();
	obj1.print();

	return 0;
}
