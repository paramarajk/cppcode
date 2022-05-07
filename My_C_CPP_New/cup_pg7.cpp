#include <iostream>
using namespace std;

class a {
public:
	int a;
	virtual void sum() {
		cout << "sum of a" << endl;
	}
};

class b : public a {
public:
	int b;
	virtual void sum() {
		cout << "sum of b " << endl;
	}
};


int main() {
	b aptr;
	a* bptr = &aptr;
	bptr->sum();

	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/tricky_question/Interview_questions/careerup=>./pg7
sum of b
*/
