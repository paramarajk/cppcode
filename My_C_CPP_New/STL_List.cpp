#include <iostream>
#include <list>
using namespace std;

template <typename T>
class mylist {
	list<T> mylst;
	typename list<T>::iterator it;
public:
	mylist(int size, int val) {
		mylst = list<T>(size, val);
		it = mylst.begin();
		cout << "mylist ctor called" << endl;
	}

	~mylist() {
		cout << "mylist dtor called" << endl;
	}

	void print() {
		for (auto i : mylst)
			cout << "List : " << i << endl;
	}

	void mylist_print() {
		for (it = mylst.begin(); it != mylst.end(); it++) {
			cout << "List-> : " << *it << endl;
		}
	}

	void myfunc() {
		cout << "Size of the list is : " << mylst.size() << endl;
		cout << "Last nodes from list : " << mylst.back() << endl;
		mylst.emplace_front(200);
		mylst.emplace_back(2000);
		it = mylst.begin();
		++it;
		mylst.emplace(it, 1000);
		it = next(mylst.begin(), 3);  //For multiple movements we can use next function
		mylst.emplace(it, 3000);
		cout << "insert" << endl;
		cout << "------" << endl;
		mylst.insert(it, 4000);
		mylist_print();
	}
};

int main() {
	mylist<int> ml(5, 10);
	//ml.print();
	ml.mylist_print();
	ml.myfunc();

	return 0;
}