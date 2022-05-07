#include <iostream>
using namespace std;

class RC {
	int count;
public:
	RC() : count(0) {}
	~RC() {}
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

//int RC::count = 0;

template<typename T>
class sha_ptr {
	T* ptr;
	RC* ref;
public:
	sha_ptr(T* p) : ptr(p) {
		if (ptr != NULL) {
			ref = new RC;
			ref->AddRef();
		}
		else {
			ptr = NULL;
			ref = NULL;
		}
	}

	~sha_ptr() {
		if (ref->RemoveRef() == 0) {
			delete ptr;
			delete ref;
			ptr = NULL;
			ref = NULL;
		}
	}

	sha_ptr(const sha_ptr<T>& other) {
		ptr = other.ptr;
		ref = other.ref;
		ref->AddRef();
	}

	sha_ptr<T>& operator=(const sha_ptr<T>& other) {
		if (this != &other) {
			if (ref->RemoveRef() == 0) {
				delete ptr;
				delete ref;
				ptr = NULL;
				ref = NULL;
			}
			ptr = other.ptr;
			ref = other.ref;
			ref->AddRef();
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
		return ref->get_count();
	}
};

class sample {
public:
	sample() {}
	~sample() {}
};

int main() {
	{	sha_ptr<sample> sh1(new sample);
	cout << "sh1 Use count is : " << sh1.use_count() << endl;
	{
		sha_ptr<sample> sh2(new sample);
		cout << "sh2 Use count is : " << sh2.use_count() << endl;
		{
			sha_ptr<sample> sh3(new sample);
			cout << "sh3 Use count is : " << sh3.use_count() << endl;
			sha_ptr<sample> sh4(new sample);
			cout << "sh4 Use count is : " << sh4.use_count() << endl;
			sh4 = sh2;
			cout << "sh4 Use count is : " << sh4.use_count() << endl;
		}
		cout << "sh2 Use count is : " << sh2.use_count() << endl;
	}
	cout << "sh1 Use count is : " << sh1.use_count() << endl;
	}
	return 0;
}