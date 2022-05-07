#include <iostream>
#include <memory>
using namespace std;


class sample {
public:
	void print() {
		cout << "sample print" << endl;
	}
};

int main() {
	unique_ptr<sample> u1(new sample);
	u1->print();

	return 0;
}