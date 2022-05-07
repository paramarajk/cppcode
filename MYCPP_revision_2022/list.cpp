#include <iostream>
#include <list>

using namespace std;

template <typename T>
class mlist {
	list<T> ml;
	typename list<T>::iterator it;
public:
	mlist(int size, int val) {
		ml = list<T>(size, val);
		it = ml.begin();
		cout << "mlist const called" << endl;
	}

	~mlist() {
		cout << "mlist dest called" << endl;
	}

	void print() {
		cout << "Range based for loop --->" << endl;
		for (auto i : ml) {
			cout << i << ' ';
		}
		cout << endl;
	}

	void print_it() {
		cout << "Printing list values using iterator ----->" << endl;
		for(it = ml.begin(); it != ml.end(); it++) {
			cout << *it << ' ';
		}
		cout << endl;
	}

	void myfunc() {
		cout << "Size of the list : " << ml.size() << endl;
		//cout << "Last node of the list : " << ml.back() << endl;
		ml.push_back(200);
		cout << "Last node of the list : " << ml.back() << endl;
		ml.emplace_front(23);
		ml.emplace_front(24);
		ml.emplace_front(25);
		ml.emplace_back(32);
		print();
		it = ml.begin();
		it++;
		ml.emplace(it, 123);
		print();
		//for multiple movement we can use next function
		it = next(ml.begin(), 3);
		cout << "3rd elemnt from list : " << *it << endl;
		ml.emplace(it, 233);
		print();
		//insert function
		ml.insert(it, 4000);
		print();
		ml.pop_back();
		print();
	}
};

int main() {
	mlist<int> ml(5, 10);
	ml.print();
	ml.print_it();
	ml.myfunc();
	return 0;
}