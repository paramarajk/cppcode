#include <iostream>
#include <map>
using namespace std;

template <typename T>
class key_map {
	map<T, T> m;
	typename map<T, T>::iterator it;
	typename map<T, T>::key_compare mycomp;
public:
	key_map(T size = 0) {
		cout << "key_map const" << endl;
		for(T i = 0; i < size; i++) {
			m.insert(make_pair(i, i + 100));
		}
		it = m.begin();
		mycomp = m.key_comp();
	}

	~key_map() {
		cout << "key_map dest" << endl;
	}

	void print() {
		for(auto it = m.begin(); it != m.end(); it++) {
			cout << "Key : " << it->first << " --> value : " << it->second << endl;
		}
	}

	void myfunc() {
		int last = m.rbegin()->first;
		it = m.begin();
		while(mycomp(it->first, last)) {
			cout << "it-first : " << it->first << " it->second : " << it->second << endl;
			it++;
		}

		//print first 2 element
		cout << "print upto middle value using key_compare" << endl;
		it = m.begin();
		int middle = m.begin()->first + 2;
		while(mycomp(it->first, middle)) {
			cout << "it-first : " << it->first << " it->second : " << it->second << endl;
			it++;
		}

	}
};


//without template
class key_map1 {
	map<int, const char*> m;
	map<int, const char*>::iterator it;
	map<int, const char*>::key_compare mycomp;
public:
	key_map1() {
		cout << "key_map1 const" << endl;
		m.insert(make_pair(100, "raju"));
		m.insert(make_pair(101, "param"));
		m.insert(make_pair(102, "kaleesh"));
		m.insert(make_pair(103, "naveena"));
		m.insert(make_pair(104, "padmin"));
		m.insert(make_pair(105, "vinoth"));

		it = m.begin();
		mycomp = m.key_comp();
	}

	~key_map1() {
		cout << "key_map1 dest" << endl;
	}

	void print() {
		cout << "size of the map : " << m.size() << endl;
		cout << "elem 102 : " << m.find(102)->second << endl;
		it = m.begin();
		for(; it != m.end(); it++) {
			cout << "it->first : " << it->first << " --> it->second : " << it->second << endl;
		}
	}

	void myfunc() {
		it = m.begin();
		int last = m.rbegin()->first;

		while(mycomp(it->first, last)) {
			cout << "key : " << it->first << " --> value : " << it->second << endl;
			it++;
		}

		//printing from middle
		cout << "Printing upto middle" << endl;
		it = m.begin();
		int middle = m.begin()->first + 2;

		while(mycomp(it->first, middle)) {
			cout << "key : " << it->first << " --> value : " << it->second << endl;
			it++;
		}
	}
};


int main() {
	/*key_map<int> km(5);
	km.print();
	km.myfunc();*/

	key_map1 km1;
	km1.print();
	km1.myfunc();

	return 0;
}
