#include <iostream>
using namespace std;

//two wheeler factory
class twowheeler {
	int enginecc, price;
public:
	twowheeler(int cc = 0, int pr = 0) : enginecc(cc), price(pr) {
		cout << "twowheeler ctor" << endl;
	}

	virtual void get_cc_and_pr() {
		cout << "twowheeler : get_cc_and_pr func" << endl;
		cout << "enginecc : " << enginecc << endl;
		cout << "price : " << price << endl;
	}

	virtual ~twowheeler() {
		cout << "twowheeler dest" << endl;
	}
};

class Royal : public twowheeler {
	int enginecc, price;
public:
	Royal(int cc = 0, int pr = 0) : enginecc(cc), price(pr) {
		cout << "Royal ctor" << endl;
	}

	void get_cc_and_pr() {
		cout << "Royal : get_cc_and_pr func" << endl;
		cout << "enginecc : " << enginecc << endl;
		cout << "price : " << price << endl;
	}

	~Royal() {
		cout << "Royal dest" << endl;
	}
};

class Hiness : public twowheeler {
	int enginecc, price;
public:
	Hiness(int cc = 0, int pr = 0) : enginecc(cc), price(pr) {
		cout << "Hiness ctor" << endl;
	}

	void get_cc_and_pr() {
		cout << "Hiness : get_cc_and_pr func" << endl;
		cout << "enginecc : " << enginecc << endl;
		cout << "price : " << price << endl;
	}

	~Hiness() {
		cout << "Hiness dest" << endl;
	}
};

class twofactory {
	twowheeler *tw;
public:
	twofactory(twowheeler *_tw = NULL) : tw(_tw) {
		cout << "twofactory const" << endl;
	}

	twowheeler* get_twofactory(string type) {
		if(type == "Royal") {
			return new Royal(240, 250000);
		} else if (type == "Hiness") {
			return new Hiness(230, 240000);
		} else {
			cout << "Wrong type, Please enter correct type!!!" << endl;
			return NULL;
		}
	}

	~twofactory() {
		if(tw != NULL) {
			delete tw;
			tw = NULL;
		}
		cout << "twofactory dest" << endl;
	}
};

//four wheeler factory
class fourwheeler {
	int enginecc, price;
public:
	fourwheeler(int cc = 0, int pr = 0) : enginecc(cc), price(pr) {
		cout << "fourwheeler ctor" << endl;
	}

	virtual void get_cc_and_pr() {
		cout << "fourwheeler : get_cc_and_pr func" << endl;
		cout << "enginecc : " << enginecc << endl;
		cout << "price : " << price << endl;
	}

	virtual ~fourwheeler() {
		cout << "fourwheeler dest" << endl;
	}
};

class audi : public fourwheeler {
	int enginecc, price;
public:
	audi(int cc = 0, int pr = 0) : enginecc(cc), price(pr) {
		cout << "audi ctor" << endl;
	}

	void get_cc_and_pr() {
		cout << "audi : get_cc_and_pr func" << endl;
		cout << "enginecc : " << enginecc << endl;
		cout << "price : " << price << endl;
	}

	~audi() {
		cout << "audi dest" << endl;
	}
};

class bmw : public fourwheeler {
	int enginecc, price;
public:
	bmw(int cc = 0, int pr = 0) : enginecc(cc), price(pr) {
		cout << "bmw ctor" << endl;
	}

	void get_cc_and_pr() {
		cout << "bmw : get_cc_and_pr func" << endl;
		cout << "enginecc : " << enginecc << endl;
		cout << "price : " << price << endl;
	}

	~bmw() {
		cout << "bmw dest" << endl;
	}
};

class fourfactory {
	fourwheeler *fw;
public:
	fourfactory(fourwheeler *_fw = NULL) : fw(_fw) {
		cout << "fourfactory const" << endl;
	}

	fourwheeler* get_fourfactory(string type) {
		if(type == "audi") {
			return new audi(340, 550000);
		} else if (type == "bmw") {
			return new bmw(330, 540000);
		} else {
			cout << "Wrong type, Please enter correct type!!!" << endl;
		}
	}

	~fourfactory() {
		if(fw != NULL) {
			delete fw;
			fw = NULL;
		}
		cout << "fourfactory dest" << endl;
	}
};

//factory 
template <typename T>
class factory {
	T *f;
public:
	factory() : f(NULL) {
		cout << "factory ctor" << endl;
	}

	T* get_factory() {
		f = new T;
		return f;
	}

	~factory() {
		if(f != NULL) {
			delete f;
			f = NULL;
		}
		cout << "factory dest" << endl;
	}
};

//client
int main() {
	factory<twofactory> *ft = new factory<twofactory>;
	twofactory *tf = ft->get_factory();
	twowheeler *tw = tf->get_twofactory("Hiness");
	tw->get_cc_and_pr();
	delete tw;
	delete tf;
	delete ft;

	return 0;
}