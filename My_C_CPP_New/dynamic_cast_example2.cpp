/*dynamic cast*/

#include <iostream>
#include <string>
using namespace std;

class window {
	string _name;
public:
	window() { cout << "ctor with no arg" << endl; }
	window(const string name) : _name(name) { cout << "ctor with 1arg" << endl; }
	virtual ~window() { cout << "dtor called" << endl; }
	void get_name() { cout << "Name is : " << _name << endl; }
};

class scrollwindow : public window {
public:
	scrollwindow(string name) : window(name) { cout << "ctor : scrollwindow" << endl; }
	~scrollwindow() { cout << "dtor : scrollwindow" << endl; }
	void scroll() { cout << "scroll()" << endl; }
};

void Dosomthing(window* w) {
	w->get_name();
	//w->scroll(); // class "window" has no member scroll()

	// check if the pointer is pointing to a scroll window
	if (scrollwindow * sw = dynamic_cast<scrollwindow*>(w)) {
		sw->scroll();
	}
	else {
		cout << "Not pointing scroll window" << endl;
	}
}

int main() {
	window* w = new window("plain window");
	scrollwindow* sw = new scrollwindow("scroll window");
	Dosomthing(w);
	Dosomthing(sw);

	delete w;
	delete sw;
	return 0;
}
