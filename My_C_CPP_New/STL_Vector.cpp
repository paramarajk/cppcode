#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class myvector {
	vector<T> myvec;
	typename vector<T>::iterator it;
public:
	myvector(int val, int size) {
		myvec = vector<T>(val, size);
		it = myvec.begin();
		cout << "myvector ctor called" << endl;
	}

	~myvector() {
		cout << "myvector dtor called" << endl;
	}

	void myfunc1() {
		cout << "size of vector is: " << myvec.size() << endl;
		cout << "capacity of vector is: " << myvec.capacity() << endl;
		cout << "max_size of vector is : " << myvec.max_size() << endl;
		cout << "Pushing the elements using push back function" << endl;
		myvec.push_back(100);
		myvec.push_back(200);
		print();
		cout << "Elements access" << endl;
		cout << "Fisrst element from the vector is : " << myvec.front() << endl;
		cout << "Last elements from the vector is : " << myvec.back() << endl;
		cout << "Removing the last element from vector " << endl;
		myvec.pop_back();
		print();
		cout << "Resizeing the vector" << endl;
		myvec.resize(3);
		cout << "before shrink-to-fit: " << myvec.capacity() << endl;
		myvec.shrink_to_fit();
		cout << "after shrink-to-fit: " << myvec.capacity() << endl;
		print();
		cout << "Emplace function in vector" << endl;
		it = myvec.emplace(myvec.begin() + 1, 500);
		it++;
		myvec.emplace(it, 600);
		myvec.emplace_back(800);
		myvec.emplace_back(700);
		print();
		cout << "Insert function in vector" << endl;
		myvec.insert(myvec.begin() + 1, 1000);
		print();
		cout << "Erase function in vector" << endl;
		myvec.erase(myvec.begin() + 2);
		print();
	}

	void print() {
		for (auto i : myvec)
			cout << "val : " << i << endl;
	}
};

int main() {
	myvector<int> m(10, 5);
	//m.print();
	m.myfunc1();
	return 0;
}