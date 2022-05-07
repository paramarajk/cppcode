#include <iostream> 
using namespace std;

class employee {
public:
	employee() {
		cout << "employee const called" << endl;
	}
	virtual void employee_info() = 0;
	virtual ~employee () {
		cout << "employee dest called" << endl;
	}
};

class software_engineer : public employee {
public:
	software_engineer() {
		cout << "software_engineer const called" << endl;
	}
	void employee_info() {
		cout << "Salary range : 5laks to 7Laks PA" << endl; 
	}
	~software_engineer() {
		cout << "software_engineer dest called" << endl;
	}
};

class lead_engineer : public employee {
public:
	lead_engineer() {
		cout << "lead_engineer const called" << endl;
	}
	void employee_info() {
		cout << "Salary range : 10Laks to 20Laks PA" << endl;
	}
	~lead_engineer() {
		cout << "lead_engineer dest called" << endl;
	}
};

int main() {
	//using pointer
	employee *e = new software_engineer();
	e->employee_info();
	delete e;

	//using refrence
	lead_engineer l;
	employee &e1 = l;
	e1.employee_info();

	return 0;
}