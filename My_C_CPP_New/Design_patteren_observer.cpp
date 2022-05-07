/*Observer patteren*/

#include <iostream>
#include <vector>
using namespace std;

class observerBase {
public:
	observerBase() { cout << "observerBase : ctor" << endl; }
	virtual ~observerBase() { cout << "observerBase : dtor" << endl; }
	virtual void update(int msg) = 0;
};

class concreate_observer : public observerBase {
	string name;
public:
	concreate_observer(string _name) : name(_name) { cout << "concreate_observer : ctor" << endl; }
	~concreate_observer() { cout << "concreate_observer : dtor" << endl; }
	void update(int msg) {
		cout << "got message : " << msg << endl;
	}
};

class subjectBase {
	vector<observerBase*> _observer;
public:
	subjectBase() { cout << "subjectBase : ctor" << endl; }
	virtual ~subjectBase() { cout << "subjectBase : dtor" << endl; }
	virtual void attach(observerBase* obj) {
		_observer.push_back(obj);
	}

	virtual void detach(observerBase* obj) {
		int count = _observer.size();
		int i = 0;
		while (i < count) {
			if (_observer[i] == obj) {
				break;
			}
			i++;
		}
		if (i < count) {
			_observer.erase(_observer.begin() + i);
		}
	}

	virtual void notify(int msg) {
		int count = _observer.size();
		int i = 0;
		while (i < count) {
			_observer[i]++->update(msg);
		}
	}
};

class concreate_subject : public subjectBase {
public:
	enum msg { ADD, REMOVE };
};

int main() {
	concreate_observer obs1("obs1");
	concreate_observer obs2("obs2");
	concreate_observer obs3("obs3");

	concreate_subject sub;
	sub.attach(&obs1);
	sub.attach(&obs2);
	sub.detach(&obs2);
	sub.attach(&obs3);

	sub.notify(concreate_subject::ADD);
	sub.notify(concreate_subject::REMOVE);

	return 0;
}