#include <iostream>
#include <map>
#include <string.h>
#include <algorithm>

using namespace std;

template <typename T, typename U> 
class mymap {
	map<T, U> mm;
	typename map<T, U>::iterator it;
public:
	mymap(T _size, U *val) {
		if (val != NULL) {
			for (T i = 0; i < _size; i++) {
				mm.insert(make_pair(i+1, val[i]));
			}
			it = mm.begin();
		}
		cout << "mymap ctor called" << endl;
	}

	~mymap() {
		cout << "mymap dtor called" << endl;
	} 

	void print() {
		for(it = mm.begin(); it != mm.end(); it++) {
			cout << "key : " << it->first << " --> value : " << it->second << endl;
		}
	}
};

int main() {
	char arr[] = "ABCDEF";
	unsigned len = strlen(arr);
	mymap<unsigned int, char> mm(len, arr);
	mm.print();

	return 0;
}