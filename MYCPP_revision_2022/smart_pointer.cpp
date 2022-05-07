//Shared pointer implementation
#include <iostream>
using namespace std;


//Reference count class
class RC {
	static int count;
public:
	RC() {
		cout << "RC const called" << endl;
	}
	~RC() {
		cout << "RC dest called" << endl;
	}

	void AddRef() {
		++count;
	}

	int RemoveRef() {
		return --count;
	}

	int get_count() {
		return count;
	}
};

int RC::count = 0;

//shared pointer class implementation
template <typename T>
class shared_ptr {
	T *ptr;
	RC *ref;

public:
	shared_ptr(T *p = NULL) : ptr(p), ref(NULL) {
		if (ptr != NULL) {
			ref = new RC;
			ref->AddRef();
		} 
		cout << "shared_ptr const called" << endl;
	}

	~shared_ptr() {
		if (ref->RemoveRef() == 0) {
			delete ptr;
			delete ref;
			ptr = NULL;
			ref = NULL;
		}
		cout << "shared_ptr dest called" << endl;
	}

	shared_ptr(const shared_ptr<T> &other) {
		if (other.ptr != NULL) {
			ptr = other.ptr;
			ref = other.ref;
			ref->AddRef();
		}
		cout << "shared_ptr copy ctor called" << endl;
	}

	shared_ptr<T>& operator= (const shared_ptr<T> &other) {
		if (this != &other) {
			if(ref->get_count() == 0) {
				delete ptr;
				delete ref;
				ptr = NULL;
				ref = NULL;
			}
			ptr = other.ptr;
			ref = other.ref;
			ref->AddRef();
		}
		cout << "shared_ptr assinment operator called" << endl;
		return *this;
	}

	T& operator* () {
		return *ptr;
	}

	T* operator-> () {
		return ptr;
	}

	int use_count() {
		return ref->get_count();
	}
};


//Sample class
class sample {
public:
	sample() { cout << "sample ctor called" << endl; }
	~sample() { cout << "sample dest called" << endl; } 
};

//Main function
int main() {
	{
		shared_ptr<sample> sh1(new sample);
		cout << "use count: " << sh1.use_count() << endl;
		{
			shared_ptr<sample> sh2(new sample);
			cout << "use count: " << sh2.use_count() << endl;	
			shared_ptr<sample> sh3(new sample);
			cout << "use count: " << sh3.use_count() << endl;	
			{
				//copy constructor
				shared_ptr<sample> sh4(sh3);
				cout << "use count: " << sh4.use_count() << endl;
			}
			{
				//assignment operator called
				shared_ptr<sample> sh5;
				sh5 = sh1;
				cout << "use count: " << sh5.use_count() << endl;
			}

		}
		{
			shared_ptr<sample> sh6(new sample);
			cout << "use count: " << sh6.use_count() << endl;	
		}
		cout << "use count: " << sh1.use_count() << endl;
		
	}
	return 0;
}