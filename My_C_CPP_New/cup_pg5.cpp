#include <iostream>
#include <exception>

using namespace std;


int main() {
	try {
		cout << "sum " << endl;
		throw 3;
	}
	/* it should be always last catch block, o.w it will throgh
	error: '...' handler must be the last handler for its try block [-fpermissive]*/
	/*catch(...) {
		cout << "dot" << endl;
	}*/
	catch (int a) {
		cout << "integer block : ";
		cout << a << endl;
	}
	catch (exception e) {
		cout << "exception" << endl;
	}
	catch (...) {
		cout << "dot" << endl;
	}
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/tricky_question/Interview_questions/careerup=>./pg5
sum
3
*/
