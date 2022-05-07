#include <iostream>
using namespace std;
#define MAX 2

class Vechile {
public:
	Vechile() { cout << "Vechile : ctor" << endl; }
	virtual Vechile* clone() = 0;
	virtual void get_Sheets() = 0;
	virtual void get_Wheelers() = 0;
	virtual ~Vechile() { cout << "Vechile : dtor" << endl; }
};

class Car : public Vechile {
	string wheelers;
	int sheats;
public:
	Car() { 
		wheelers = "Four";
		sheats = 4;
		cout << "Car : ctor" << endl; 
	}
	void get_Sheets() {
		cout << "Car : Sheets : " << sheats << endl;
	}

	void get_Wheelers() {
		cout << "Car : Wheelers : " << wheelers << endl;
	}

	Vechile* clone() {
		return new Car(*this);
	}

	~Car() { cout << "Car : dtor" << endl; }
};

class Bike : public Vechile {
	string wheelers;
	int sheats;
public:
	Bike() {
		wheelers = "Two";
		sheats = 2;
		cout << "Bike : ctor" << endl;
	}

	void get_Sheets() {
		cout << "Bike : Sheets : " << sheats << endl;
	}

	void get_Wheelers() {
		cout << "Bike : Wheelers : " << wheelers << endl;
	}

	Vechile* clone() {
		return new Bike(*this);
	}

	~Bike() { cout << "Bike : dtor" << endl; }
};

class Vechile_Builder {
	Vechile* Vb;
	int ch;
public:
	Vechile_Builder(int c = 0) : ch(c) {

		if (ch == 1) {
			Vb = new Car;
		}
		else if (ch == 2) {
			Vb = new Bike;
		}
		else {
			Vb = NULL;
		}
		cout << "Vechile_Builder : ctor" << endl;
	}

	void Make_Vechile() {
		Vechile* v = Vb->clone();
		v->get_Sheets();
		v->get_Wheelers();
	}

	~Vechile_Builder() {
		if (Vb != NULL) {
			delete Vb;
			Vb = NULL;
			cout << "Vechile_Builder : dtor" << endl;
		}
	}
};

int main() {
	int val;
	cout << "Enter 0/exit 1/Car 2/Bike" << endl;
	cin >> val;
	if (val == 0) return 0;
	Vechile_Builder* v = new Vechile_Builder(val);
	v->Make_Vechile();
	delete v;
	return 0;
}