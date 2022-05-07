#include <iostream>
using namespace std;

class RC {
	int ref;
public:
	RC(int r = 0) : ref(r) {}
	void addRef() {
		ref++;
	}
	int deleteRef() {
		return ref--;
	}
	int get_count() {
		return ref;
	}
};


template <typename T>
class Test {
	T* data;
	RC* refcnt;
public:
	Test(T* t = NULL) :data(t) {
		if (!data)
			data = new T;
		refcnt = new RC();
		refcnt->addRef();
	}
	Test(const Test& rhs) :data(rhs.data), refcnt(rhs.refcnt) {
		refcnt->addRef();
	}
	Test& operator = (const Test& rhs) {
		if (this != &rhs) {
			cout << refcnt->get_count() << endl;
			//cout << refcnt->deleteRef() << endl;
			if (refcnt->deleteRef() == 0) {
				delete data;
				delete refcnt;
				cout << "inside if, =" << refcnt->get_count() << endl;
			}
			data = rhs.data;
			refcnt = rhs.refcnt;
			refcnt->addRef();
		}
		return *this;
	}

	T& operator* () {
		return *data;
	}

	T* operator-> () {
		return data;
	}

	void use_count() {
		cout << "Use count is : " << refcnt->get_count() << endl;
	}
	~Test() {
		if (refcnt->deleteRef() == 0) {
			delete data;
			delete refcnt;
		}
	}
};

class sample {
	int a;
public:
	sample(int x = 0) : a(x) {}
	~sample() {}
};

int main() {
	Test<sample> t1;
	t1.use_count();
	{
		Test<sample> t2(t1);
		t2.use_count();
		{
			Test<sample> t3;
			t3 = t2;
			t2.use_count();
		}
		t2.use_count();
	}
	t1.use_count();
	return 0;
}
