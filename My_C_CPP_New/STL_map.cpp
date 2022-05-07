#include <iostream>
#include <map>
#include <string.h>
using namespace std;

template <typename T, typename U>
class mymap {
	map<T, U> mmap;
	typename map<T, U>::iterator it;
	typename map<T, U>::key_compare mycomp;
	int size;
public:
	mymap(U *value, T size) : size(size) {
		for (T i = 0; i < size; i++) {
			mmap.insert(make_pair(i+1, value[i]));
		}
		it = mmap.begin();
		mycomp = mmap.key_comp();
		cout << "mymap ctor" << endl;
	}

	~mymap() {
		cout << "mymap dtor" << endl;
	}

	void print() {
		for (it = mmap.begin(); it != mmap.end(); it++) {
			cout << "Key is : " << it->first << " Value is : " << it->second << endl;
		}
	}

	void myfunc() {
		cout << "find concept called" << endl;
		it = mmap.find(3);
		cout << it->first << " --> " << it->second << endl;
		cout << "Emplace in map" << endl;
		mmap.emplace(10, 'J');
		mmap.emplace(9, 'I');
		mmap.insert(make_pair(8, 'H'));
		print();

		cout << "Key compare example" << endl;
		it = mmap.begin();
		int highest = mmap.rbegin()->first;
		while (mycomp(it->first, highest)) {
			cout << "Key is : " << it->first << " Heighest :" << highest << endl;
			it++;
		}
	}
};

int main() {
	char arr[] = "ABCD";
	int len = strlen(arr);
	mymap<int, char> m(arr, len);
	m.print();
	m.myfunc();
	return 0;
}