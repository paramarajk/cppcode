#include<iostream>
using namespace std;

class CA
{
private:
	~CA() { cout << "CA:: dtor called" << endl; }
public:
	CA() { cout << "CA :: ctor called" << endl; }
	void clearptr() {
		cout << "CA :: clearptr called" << endl;
		delete this;
	}
};

int main()
{
	/*CA obj;*/ /*unable to create the static object, because destructor is private*/
	CA* p = new CA;
	p->clearptr();

	return 0;
}
