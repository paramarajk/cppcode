#include <iostream>
#include <mutex>
using namespace std;

class singleton {
	static singleton* sinst;
	static int emp_salary;
	static mutex mu;
	singleton() {
		cout << "singleton ctor" << endl;
	} 

	singleton(const singleton& obj) {
		if (sinst != NULL) {
			delete sinst;
		}
		sinst = obj.sinst;
		emp_salary = obj.emp_salary;
		cout << "singleton copy const" << endl;
	}

	singleton& operator= (const singleton& obj) {
		if(this != &obj) {
			if (sinst != NULL) {
				delete sinst;
			}
			sinst = obj.sinst;
			emp_salary = obj.emp_salary;
		}
		cout << "singleton assignment operator" << endl;
		return *this;
	}

	~singleton() {
		cout << "singleton dest" << endl;
	}

public:
	static void update_salary(int x) {
		emp_salary = x;
		cout << "singleton update_salary func" << endl;
	}

	void print() {
		cout << "singleton print func" << endl;
		cout << "emp_salary : " << emp_salary << endl;
	}

	static singleton* get_inst() {
		if (sinst == 0) {
			lock_guard<mutex> guard(mu);
			if (sinst == 0) {
				sinst = new singleton();	
			}
		}
		cout << "singleton get_inst func" << endl;
		return sinst;
	}

	void clearptr() {
		if (sinst != 0) {
			delete sinst;
		}
		cout << "singleton clearptr func" << endl;
	}
};

singleton* singleton::sinst = 0;
int singleton::emp_salary = 0;
mutex singleton::mu;

int main() {
	singleton *inst = singleton::get_inst();
	inst->update_salary(10000);
	inst->print();
	inst->clearptr();

	return 0;
}