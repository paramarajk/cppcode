#include<iostream>
using namespace std;
/*An example on inheritance and the role of 'private' access specifier.*/

class CA
{
private:
	int a, b;
public:
	void input(int x, int y)
	{
		cout << "CA-input, enter 2 nos" << endl;
		//cin >> a >> b;
		a = x; b = y;
	}
	void print()
	{
		cout << "CA-print, a = " << a << ",b=" << b << endl;
	}
};

/********************/
class CB :private CA
{
private:
	int a, b;
	/*void CA::input() {}
        void CA::print() {}*/
public:
	void input(int x, int y)
	{
		CA::input();
		cout << "CB-input, enter 2 nos" << endl;
		//cin >> a >> b;
		a = x;  b = y;
	}
	void print()
	{
		CA::print(20, 30);
		cout << "CB-print, a = " << a << ",b=" << b << endl;
	}
};

/******consumer code************/
int main()
{
	cout << "size of CB " << sizeof(CB) << endl; /*CA data members + CB data members*/
	CB obj1;

	obj1.input(10, 20);
	obj1.print();

	return 0;
}

