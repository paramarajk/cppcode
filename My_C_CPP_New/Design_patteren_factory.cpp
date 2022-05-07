/*Factory design patteren*/
#include <iostream>
using namespace std;

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

class factory {
	two_factory* tw;
public:
	factory(two_factory *ptr = NULL) : tw(ptr) { cout << "factory : ctor " << endl; }

	two_factory* get_factory(string type) {
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

	~factory() {
		if (tw != NULL) {
			delete tw;
			tw = NULL;
			cout << "factory: dtor called" << endl;
		}
		else {
			cout << " test" << endl;
		}
	}
};


int main() {
	factory *f = new factory;
	two_factory *tf = f->get_factory("UNICORN");
	tf->body_type();
	tf->max_speed();
	tf->price();
	delete f;

	return 0;
}