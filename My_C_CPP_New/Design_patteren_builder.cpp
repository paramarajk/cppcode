/*Builder Design Patteren*/

#include <iostream>
using namespace std;

class Car {
	string Engine, Door, Wheel, Seats;
public:
	Car() { cout << "Car : ctor" << endl; }
	~Car() { cout << "Car : dtor" << endl; }
	void set_Engine(string engine) { Engine = engine; }
	void set_Door(string door) { Door = door; }
	void set_Wheel(string wheel) { Wheel = wheel; }
	void set_Seats(string seats) { Seats = seats; }
	void get_Car_details() {
		cout << "Car Engine : " << Engine << endl;
		cout << "Car Door : " << Door << endl;
		cout << "Car Wheel : " << Wheel << endl;
		cout << "Car Seats : " << Seats << endl;
	}
};

class Car_Build {
public:
	Car_Build() { cout << "Car_Build : ctor" << endl; }
	virtual ~Car_Build() { cout << "Car_Build : dtor" << endl; }
	virtual void build_Engine() = 0;
	virtual void build_Door() = 0;
	virtual void build_Wheel() = 0;
	virtual void build_Seats() = 0;
	virtual Car* get_Car() = 0;
};

class BMW_Car : public Car_Build {
	Car* _car;
public:
	BMW_Car() { 
		_car = new Car;
		cout << "BMW_Car : ctor" << endl; 
	}
	void build_Engine() {
		_car->set_Engine("BMW Engine");
	}

	void build_Door() {
		_car->set_Door("BMW Door");
	}

	void build_Wheel() {
		_car->set_Wheel("BMW Wheel");
	}

	void build_Seats() {
		_car->set_Seats("BMW Shets");
	}

	Car* get_Car() {
		return _car;
	}

	~BMW_Car() { 
		if (_car != NULL) {
			delete _car;
			_car = NULL;
		}
		cout << "BMW_Car : dtor" << endl; 
	}

};

class VW_Car : public Car_Build {
	Car* _car;
public:
	VW_Car() {
		_car = new Car;
		cout << "VW_Car : ctor" << endl;
	}
	void build_Engine() {
		_car->set_Engine("VW Engine");
	}

	void build_Door() {
		_car->set_Door("VW Door");
	}

	void build_Wheel() {
		_car->set_Wheel("VW Wheel");
	}

	void build_Seats() {
		_car->set_Seats("VW Shets");
	}

	Car* get_Car() {
		return _car;
	}

	~VW_Car() { 
		if (_car != NULL) {
			delete _car;
			_car = NULL;
		}
		cout << "VW_Car : dtor" << endl; 
	}

};

class Director {
	Car_Build* _Cbuilder;
public:
	Director(Car_Build *Cbuilder) {
		_Cbuilder = Cbuilder;
		cout << "Director : ctor" << endl;
	}

	Car* Get_Car() {
		return _Cbuilder->get_Car();
	}

	void Build_Car() {
		_Cbuilder->build_Engine();
		_Cbuilder->build_Door();
		_Cbuilder->build_Wheel();
		_Cbuilder->build_Seats();
	}

	~Director() {
		if (_Cbuilder != NULL) {
			delete _Cbuilder;
			_Cbuilder = NULL;
			cout << "Director : dtor" << endl;
		}
	}
};

int main() {
	Car_Build* cb = new BMW_Car;
	Director* d = new Director(cb);
	d->Build_Car();
	Car* c1 = d->Get_Car();
	c1->get_Car_details();

	delete d;
	return 0;
}