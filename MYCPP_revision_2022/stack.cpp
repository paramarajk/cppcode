//Stack implementation
#include <iostream>
using namespace std;

template <typename T>
class class_stack {
	T *arr;
	int capacity, Size, top;
public:
	class_stack(int _size = 0) : Size(_size) {
		arr = new T[Size];
		capacity = Size;
		top = -1;
	}

	~class_stack() {
		if(arr != NULL) {
			delete [] arr;
		}
	}

	bool isEmpty() {
		return top == -1;
	}

	bool isFull() {
		return top == capacity - 1;
	}

	int Size_func() {
		return top + 1;
	}

	void push(T val) {
		if(isFull()) {
			cout << "stack is full, unable to push val ,returning from here...!!!" << endl;
			return;
		}
		cout << "Pusing the value into stack : " << val << endl;
		arr[++top] = val;
	}

	int pop() {
		if(isEmpty()) {
			cout << "stack is empty , can't pop element...!!!" << endl;
			return 0;
		}
		cout << "poping up the value from stack : " << arr[top] << endl;
		return arr[top--];
	}

	void print() {
		for(int i = 0; i <= top; i++) {
			cout << "arr[" << i << "] -> " << arr[i] << endl;
		}
	}
};


int main() {
	class_stack<int> st(5);
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	st.push(60);
	cout << "Size of the stack is : " << st.Size_func() << endl;
	st.print();
	st.pop();
	st.pop();
	st.pop();
	st.pop();
	st.pop();
	st.pop();

	return 0;
}