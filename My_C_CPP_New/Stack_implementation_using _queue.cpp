#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class my_stack {
	queue<int> q1, q2;
public:
	void push(int num) {
		q1.push(num);
	}

	int pop() {
		if (q1.empty()) {
			cout << "Underflow!!!" << endl;
			return 0;
		}

		int front = 0;
		while (!q1.empty()) {
			if (q1.size() != 1) {
				q2.push(q1.front());
			}
			else {
				front = q1.front();
			}
			q1.pop();
		}

		while (!q2.empty()) {
			q1.push(q2.front());
			q2.pop();
		}

		return front;
	}
};

int main() {
	vector<int> mv = {1, 2, 3, 4, 5};
	my_stack ms;
	
	cout << "Pushed elements into stack" << endl;
	for (auto i : mv) {
		ms.push(i);
		cout << i << "\t";
	}
	cout << endl;
		
	cout << "popped elements from stack" << endl;
	for (int i = 0; i < mv.size(); i++) {
		cout << ms.pop() << "\t";
	}
	cout << endl;

	return 0;
}