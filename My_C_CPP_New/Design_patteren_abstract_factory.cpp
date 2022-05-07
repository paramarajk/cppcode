/*Abstract Factory design patteren*/
#include <iostream>
using namespace std;

/*Two wheeler factory*/
class two_factory {
public:
	two_factory() { cout << "two_factory : ctor " << endl; }
	virtual void body_type() = 0;
	virtual void price() = 0;
	virtual void max_speed() = 0;
	virtual ~two_factory() { cout << "two_factory : dtor " << endl; }
};

class YAMAHA : public two_factory {
public:

	YAMAHA() { cout << "YAMAHA: ctor " << endl; }

	void body_type() {
		cout << "YAMAHA: Body type is metal" << endl;
	}

	void price() {
		cout << "YAMAHA: Price is : 1,00,000/-" << endl;
	}

	void max_speed() {
		cout << "YAMAHA: max_speed is : 160kmph" << endl;
	}

	~YAMAHA() { cout << "YAMAHA : dtor " << endl; }
};

class UNICORN : public two_factory {
public:

	UNICORN() { cout << "UNICORN : ctor " << endl; }

	void body_type() {
		cout << "UNICORN: Body type is metal with fiber" << endl;
	}

	void price() {
		cout << "UNICORN: Price is : 1,20,000/-" << endl;
	}

	void max_speed() {
		cout << "UNICORN: max_speed is : 180kmph" << endl;
	}

	~UNICORN() { cout << "UNICORN : dtor " << endl; }
};

class factory2 {
	two_factory* tw;
public:
	factory2(two_factory* ptr = NULL) : tw(ptr) { cout << "factory2 : ctor " << endl; }

	two_factory* get_factory2(string type) {
		if (type == "YAMAHA") {
			tw = new YAMAHA;
		}
		else if (type == "UNICORN") {
			tw = new UNICORN;
		}
		else {
			cout << "Enter correct choice" << endl;
			return NULL;
		}
		return tw;
	}

	~factory2() {
		if (tw != NULL) {
			delete tw;
			tw = NULL;
			cout << "factory2 : dtor called" << endl;
		}
	}
};

/*Four wheeler factory*/
class four_factory {
public:
	four_factory() {
		cout << "four_factory : ctor" << endl;
	}
	virtual void body_type() = 0;
	virtual void max_speed() = 0;
	virtual void price() = 0;
	virtual ~four_factory() {
		cout << "four_factory : dtor" << endl;
	}
};

class BMW : public four_factory {
public:
	BMW() { cout << "BMW : ctor" << endl; }
	
	void body_type() {
		cout << "BMW : body type is metal" << endl;
	}

	void max_speed() {
		cout << "BMW : max speed is : 250kmph" << endl;
	}

	void price() {
		cout << "BMW : prce is 45Lacks" << endl;
	}

	~BMW() { cout << "BMW : dtor" << endl; }
};

class VW : public four_factory {
public:
	VW() { cout << "VW : ctor" << endl; }

	void body_type() {
		cout << "VW : body type is metal with plastic" << endl;
	}

	void max_speed() {
		cout << "VW : max speed is : 200kmph" << endl;
	}

	void price() {
		cout << "VW : prce is 15Lacks" << endl;
	}

	~VW() { cout << "VW : dtor" << endl; }
};

class factory4 {
	four_factory* fw;
public:
	factory4(four_factory *ptr = NULL) : fw(ptr) { cout << "four_factory : ctor" << endl; }

	four_factory* get_factory4(string type) {
		if (type == "BMW") {
			fw = new BMW;
		}
		else if (type == "VW") {
			fw = new VW;
		}
		else {
			cout << "Enter correct choice" << endl;
		}
		return fw;
	}
	~factory4() {
		if (fw != NULL) {
			delete fw;
			fw = NULL;
			cout << "factory4 : dtor " << endl;
		}
	}
};

/*Abstarct factory class*/
template<typename T>
class factory {
	T* f;
public:
	factory(T* ptr = NULL) : f(ptr) {
		cout << "factory : ctor" << endl;
	}
	T* get_factory() {
		f = new T;
		return f;
	}
	~factory() {
		if (f != NULL) {
			delete f;
			f = NULL;
			cout << "factory : dtor" << endl;
		}
	}
};

/*Consumer code*/
int main() {
	factory<factory2> *f = new factory<factory2>;
	factory2* fw = f->get_factory();
	two_factory *ff = fw->get_factory2("UNICORN");
	ff->body_type();
	ff->max_speed();
	ff->price();
	delete f;
	
	return 0;
}