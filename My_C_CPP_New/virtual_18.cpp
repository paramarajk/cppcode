/*Calling virtual methods in constructor/destructor in C++*/
#include<iostream>
using namespace std;

class dog
{
public:
	dog()
	{
		cout << "Constructor called" << endl;
		bark();
	}

	virtual ~dog()
	{
		bark();
	}

	virtual void bark()
	{
		cout << "Virtual method called" << endl;
	}

	void seeCat()
	{
		bark();
	}
};

class Yellowdog : public dog
{
public:
	Yellowdog()
	{
		cout << "Derived class Constructor called" << endl;
	}
	void bark()
	{
		cout << "Derived class Virtual method called" << endl;
	}
};

int main()
{
	Yellowdog d;
	d.seeCat();
}

/*output :
Constructor called
Virtual method called
Derived class Constructor called
Derived class Virtual method called
Virtual method called
*/
