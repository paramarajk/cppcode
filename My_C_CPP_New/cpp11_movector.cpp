/*move conatrctor*/
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class sample {
	char* _name;
public:
	sample(const char* name = NULL) {
		if (name != NULL) {
			_name = new char[strlen(name)];
			strcpy(_name, name);
		}
		
		cout << "ctor called" << endl;
	}

	~sample() {
		if (_name != NULL) {
			delete [] _name;
			_name = NULL;
		}
		cout << "dtor called" << endl;
	}

	sample(const sample& obj) {
		if (obj._name != NULL) {
			_name = new char[strlen(obj._name)];
			strcpy(_name, obj._name);
			cout << "copy ctor called" << endl;
		}
	}

	sample(sample&& obj) {
		if (obj._name != NULL) {
			_name = obj._name;
			obj._name = NULL;
			cout << "Move ctor called" << endl;
		}
	}

	sample& operator=(sample&& obj) {
		if (this != &obj) {
			if (obj._name != NULL) {
				_name = obj._name;
				obj._name = NULL;
				cout << "move assignment called" << endl;
			}
		}
		return *this;
	}

	void print() {
		cout << "Name is : " << _name << endl;
	}

};

int main() {
	sample s1("Param");
	sample s2(move(s1));
	sample("nagamastan");
	s2.print();

	cout << "Vector used" << endl;
	cout << "-----------" << endl;
	vector<sample> v(1, sample("Guru"));
	v.push_back(sample("Raju"));
	v.push_back(s2);
	vector<sample>::iterator it = v.begin();
	for (; it != v.end(); it++) {
		(*it).print();
	}

	cout << "move assignment" << endl;
	sample s3("Guru");
	s3.print();
	sample s4("Raju");
	s3 = move(s4);
	s3.print();
	return 0;
}
