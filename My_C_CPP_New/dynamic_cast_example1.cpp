#include <iostream>
using namespace std;

class dynamic_castA {
public:
	dynamic_castA() {
		cout << "dynamic_castA const called" << endl;
	}

	virtual ~dynamic_castA() {
		cout << "dynamic_castA dest called" << endl;
	}

	virtual void dynamic_cast_show() {
		cout << "dynamic_castA_show func called" << endl;
	}

	void dynamic_castA_print() {
		cout << "dynamic_castA_print func called" << endl;
	}
};

class dynamic_castB : public dynamic_castA {
public:
	dynamic_castB() {
		cout << "dynamic_castB const called" << endl;
	}

	~dynamic_castB() {
		cout << "dynamic_castB dest called" << endl;
	}

	void dynamic_cast_show() {
		cout << "dynamic_castB_show func called" << endl;
	}

	void dynamic_castB_print() {
		cout << "dynamic_castB_print func called" << endl;
	}
};

int main() {
	cout << "Dynamic binding" << endl;
	cout << "---------------" << endl;
	{
		dynamic_castA* dca = dynamic_cast<dynamic_castA*> (new dynamic_castB);
		//downcating --> need to do exlicitly
		dynamic_castB* dcb = dynamic_cast<dynamic_castB*> (dca);
		if (dcb != NULL) {
			cout << "Dynamic_cast is success: dcb --> " << dcb << endl;
			dcb->dynamic_cast_show();
			dcb->dynamic_castB_print();
			dcb->dynamic_castA_print();
		}
		else {
			cout << "Dynamic_cast is failed: dcb -->" << dcb << endl;
		}
		delete dcb;
	}
	return 0;
}
