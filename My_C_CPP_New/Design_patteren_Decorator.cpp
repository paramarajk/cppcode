#include <iostream>
#include <string>
using namespace std;

class Car {
public:
	Car() { cout << "Car : ctor" << endl; }
	virtual void Create_Car() = 0;
	virtual void Get_car() {

	}
	virtual ~Car() { cout << "Car : dtor" << endl; }
};

class Car_imple : public Car {
	string Engine, Door, Wheel, Glass;
public:
	Car_imple() { cout << "Car_imple : ctor" << endl; }

	void set_Engine(string engine) {
		Engine = engine;
	}

	void set_Door(string door) {
		Door = door;
	}

	void set_Wheel(string wheel) {
		Wheel = wheel;
	}

	void set_Glass(string glass) {
		Glass = glass;
	}

	Car_imple& get_car_impl_obj() {
		return *this;
	}

	void Create_Car() {
		set_Door("White Door");
		set_Glass("White Glass");
		set_Wheel("White wheel");
		//return new Car_imple(*this);
	}

	void Get_car() {
		cout << "Engine : " << Engine << endl;
		cout << "Door : " << Door << endl;
		cout << "Wheel : " << Wheel << endl;
		cout << "Glass : " << Glass << endl;
	}

	~Car_imple() { cout << "Car_imple : dtor" << endl; }
};

class car_decorator : public Car {
protected:
	Car* car;
public:
	car_decorator(Car* car = NULL) : car(car) {
		cout << "car_decorator : ctor" << endl;
	}
	void Create_Car() {
		
	}

	virtual Car* get_car_obj() {
		return car;
	}

	virtual void Add_Engine(Car_imple *car) = 0;

	~car_decorator() {
		if (car != NULL) {
			delete car;
			car = NULL;
			cout << "car_decorator : dtor" << endl;
		}
	}
};

class car_decorator_petrol : public car_decorator {
	
public:
	car_decorator_petrol(Car *car = NULL) : car_decorator(car) { 
		cout << "car_decorator_petrol : ctor" << endl; 
	}
	void Create_car() {
		car = get_car_obj();
		car->Create_Car();
		Add_Engine(dynamic_cast<Car_imple*>(car));
	}

	void Add_Engine(Car_imple* car) {
		
		car->set_Engine("Petrol Engine");
		//return car;
	}
	
	~car_decorator_petrol() { cout << "car_decorator_petrol : dtor" << endl; }
};

class car_decorator_disel : public car_decorator {
	
public:
	car_decorator_disel(Car* car = NULL) : car_decorator(car) {
		cout << "car_decorator_disel : ctor" << endl;
	}
	void Create_car() {
		car = get_car_obj();
		car->Create_Car();
		Add_Engine(dynamic_cast<Car_imple*>(car));
	}

	void Add_Engine(Car_imple* car) {
		car->set_Engine("Disel Engine");
		//return car;
	}

	~car_decorator_disel() { cout << "car_decorator_disel : dtor" << endl; }
};

int main() {
	Car* c = new Car_imple;
	c->Create_Car();

	car_decorator *cd  = new car_decorator_petrol(c);
	cd->Create_Car();
	c->Get_car();

	delete c;
	delete cd;
	return 0;
}

/*class Component
{
public:
	virtual string Read() = 0;
};
class Decorator : public Component
{
protected:
	Component *f;
	Decorator(Component *f) : f(f)
	{
	}
};
class File : public Component
{
	string filename;
public:
	string Read()
	{
		return "Hello";
	}
};
class Compress : public Decorator
{
public:
	Compress(Component *f) : Decorator(f)
	{
	}
public:
	string Read()
	{
		return "Compressed " + f->Read();
	}
};
class Encrypt : public Decorator
{
public:
	Encrypt(Component *f) : Decorator(f)
	{
	}
public:
	string Read()
	{
		return "Encrypted " + f->Read();
	}
};

void main()
{
	File f;
	Compress c1(&f);
	Encrypt e1(&f);
	Encrypt e2(&c1);
	Compress c2(&e1);

	cout << f.Read() << endl; // hello

	cout << e1.Read() << endl; // encrypted hello
	cout << e2.Read() << endl; // encrypted compresses hello

	cout << c1.Read() << endl; // compressed hello
	cout << c2.Read() << endl; // compressed encrypted hello
	//hello
	//encrypted hello
	//encrypted compressed hello
	//compressed hello
	//compressed encrypted hello
}*/