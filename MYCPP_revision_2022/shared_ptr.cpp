#include <iostream> 
using namespace std;

class Rc {
	static int count;
public:
	Rc() {
		cout << "Rc ctor" << endl;
	}

	~Rc() {
		cout << "Rc dtor" << endl;
	}

	static void Addref() {
		count++;
	}

	static int Removeref() {
		return --count;
	}

	static int get_use_count() {
		return count;
	}
};

int Rc::count = 0;

template <typename T>
class shptr {
	T *ptr;
	Rc *rc;
public:
	shptr(T *ptr = NULL) : ptr(ptr), rc(new Rc) {
		cout << "shptr ctor" << endl;
		rc->Addref();
	}

	~shptr() {
		if(rc->Removeref() == 0) {
			delete ptr;
			delete rc;
		}
		cout << "shptr dest" << endl;
	}

	shptr(const shptr<T> &obj) {
		ptr = obj.ptr;
		rc = obj.rc;
		rc->Addref();
		cout << "shptr copy ctor" << endl;
	}

	shptr<T>& operator=(const shptr<T> &obj) {
		if(this != &obj) {
			if(rc->Removeref() == 0) {
				delete ptr;
				delete rc;
			}
			ptr = obj.ptr;
			rc = obj.ec;
			rc->Addref();
			cout << "shptr assign operator" << endl;
		}
		return *this;
	}

	T& operator*() {
		return *ptr;
	}

	T* operator->() {
		return ptr;
	}

	int use_count() {
		return rc->get_use_count();
	}

};

class sample {
public:
	void print() {
		cout << "sample print func" << endl;
	}
};

int main() {
	sample *s = new sample;
	shptr<sample> s1(s);
	s->print();
	cout << "shptr count is : " << s1.use_count() << endl;

	return 0;
}