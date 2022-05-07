#include <iostream>
using namespace std;

class twowheeler_factory {
public:
	twowheeler_factory() {
		cout << "twowheeler_factory const" << endl;
	}
	virtual void enginecc() = 0;
	virtual void price() = 0;
	virtual ~twowheeler_factory() {
		cout << "twowheeler_factory dest" << endl;
	}
};

class honda_hiness : public twowheeler_factory {
	int _enginecc;
	int _price;
public:
	honda_hiness(int cc = 0, int pr = 0) : _enginecc(cc), _price(pr) {
		cout << "honda_hiness const" << endl;
	}

	void enginecc() {
		cout << "honda_hiness : enginecc -> : " << _enginecc << endl;
	}

	void price() {
		cout << "honda_hiness : price -> : " << _price << endl;
	}

	~honda_hiness() {
		cout << "honda_hiness dest" << endl;
	}
};


class royal_enfield : public twowheeler_factory {
	int _enginecc;
	int _price;
public:
	royal_enfield(int cc = 0, int pr = 0) : _enginecc(cc), _price(pr) {
		cout << "royal_enfield const" << endl;
	}

	void enginecc() {
		cout << "royal_enfield : enginecc -> : " << _enginecc << endl;
	}

	void price() {
		cout << "royal_enfield : price -> : " << _price << endl;
	}

	~royal_enfield() {
		cout << "royal_enfield dest" << endl;
	}
};


//factory class
class factory {
	twowheeler_factory *_tw;
public:
	factory(twowheeler_factory *tw = NULL) : _tw(tw) {
		cout << "factory const" << endl;
	}

	twowheeler_factory* get_factory(const char *type) {
		cout << "factory get_factory func" << endl;
		if (type == "Honda") {
			return new honda_hiness(350, 237000);
		} else if (type == "Royal") {
			return new royal_enfield(350, 250000);
		} else {
			cout << "Please provide proper type of twowheeler...." << endl;
			return NULL;
		}
	} 

	~factory() {
		if (_tw != NULL) {
			delete _tw;
			_tw = NULL;
		}
		cout << "factory dest" << endl;
	}
};


//Client
int main() {
	factory *fp = new factory();
	cout << "HONDA---------------->" << endl;
	twowheeler_factory *tw = fp->get_factory("Honda");
	tw->enginecc();
	tw->price();
	delete tw;
	cout << endl;

	cout << "ROYAL---------------->" << endl;
	twowheeler_factory *tw1 = fp->get_factory("Royal");
	tw1->enginecc();
	tw1->price();
	delete tw1;
	delete fp;

	return 0;
}