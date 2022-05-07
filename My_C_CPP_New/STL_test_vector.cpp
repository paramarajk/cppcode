#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class myvec {
	vector<T> mv;
	typename vector<T>::iterator it;
public:
	myvec(int size, int val) {
		mv = vector<T>(size, val);
		it = mv.begin();
		cout << "myvec ctor called" << endl;
	}

	~myvec() {
		cout << "myvec dtor called" << endl;
	}

	void print() {
		cout << "Printing Vector Elements ---->" << endl; 
		for(auto i : mv) {
			cout << i << ' ';
		}
		cout << endl;
	}

	void myfunc() {
		cout << "Sizeof the vector : " << mv.size() << endl;
		cout << "capacity of the vector : " << mv.capacity() << endl;
		cout << "max size of the vector : " << mv.max_size() << endl;
		mv.push_back(100);
		mv.emplace(mv.begin(), 10);
		print();
		cout << "First element of the vector : " << mv.front() << endl;
		cout << "Last element of the vector : " << mv.back() << endl;
		mv.pop_back();
		print();
		cout << "Sizeof the vector : " << mv.size() << endl;
		mv.resize(3);
		cout << "Sizeof the vector : " << mv.size() << endl;
		print();
		cout << "before shrink-to-fit: " << mv.capacity() << endl;
		mv.shrink_to_fit();
		cout << "after shrink-to-fit: " << mv.capacity() << endl;
		print();
		mv.insert(mv.begin(), 1);
		print();
		mv.erase(mv.begin() + 2);
		print();
		cout << "2 index value : " << mv[2] << endl;
	}
};


int main() {
	myvec<int> mv(5, 20);
	mv.print();
	mv.myfunc();
	return 0;
}