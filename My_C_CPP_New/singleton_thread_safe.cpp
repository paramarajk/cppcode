/*compiler option for this code is : g++ singlton_thread_safe.cpp -o singlton_thread_safe -std=c++11 -pthread*/
#include <iostream>
#include <string.h>
//#include <pthread.h>
using namespace std;

/*singleton_thread_safe*/
class singleton_thread_safe {
	static int count;
	static singleton_thread_safe* sinst;
	int _age;
	char* _name;
	static pthread_mutex_t mu;

	singleton_thread_safe(int age = 0, char* name = NULL) : _age(age), _name(name) {
		cout << "singleton_thread_safe const called" << endl;
	}

	~singleton_thread_safe() {
		cout << "singleton_thread_safe dest called" << endl;
	}

	static void AddRef() {
		count++;
	}

	static void RemoveRef() {
		count--;
	}

public:
	/*here we are using Double-Checked Locking*/

	static singleton_thread_safe* GetInst() {
		if (sinst == NULL) {
			pthread_mutex_lock(&mu);
			if (sinst == NULL) {
				sinst = new singleton_thread_safe();
			}
			pthread_mutex_unlock(&mu);
		}
		AddRef();
		return sinst;
	}

	void singleton_thread_safe_setval(int age, char* name) {
		_age = age;
		_name = new char[strlen(name)];
		strcpy(_name, name);
		cout << "singleton_thread_safe_setval func called" << endl;
	}

	void singleton_thread_safe_print() {
		cout << "singleton_thread_safe_print func called" << endl;
		cout << "Name is : " << _name << endl;
		cout << "Age is : " << _age << endl;
	}

	static void free_inst() {
		RemoveRef();

		cout << "The count value is : " << count << endl;
		cout << "free_instance func called" << endl;
		if (count == 0 && sinst != NULL) {
			delete sinst;
			sinst = NULL;
		}
	}
};

singleton_thread_safe* singleton_thread_safe::sinst = NULL;
int singleton_thread_safe::count = 0;
pthread_mutex_t singleton_thread_safe::mu = PTHREAD_MUTEX_INITIALIZER;

int main() {
	singleton_thread_safe::GetInst()->singleton_thread_safe_setval(31, "Paramaraj karuppasamy");
	singleton_thread_safe::GetInst()->singleton_thread_safe_print();
	singleton_thread_safe::free_inst();
	singleton_thread_safe::free_inst();

	return 0;
}

/*output :
singleton_thread_safe const called
singleton_thread_safe_setval func called
singleton_thread_safe_print func called
Name is : Paramaraj karuppasamy
Age is : 31
The count value is : 1
free_instance func called
The count value is : 0
free_instance func called
singleton_thread_safe dest called
*/
