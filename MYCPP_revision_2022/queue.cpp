#include <iostream>
using namespace std;

template <typename T>
class Queue {
	T *arr;
	int front, rear, size, count;
public:
	Queue(int s = 0) : size(s) {
		front = rear = -1;
		count = 0;
		if (size != 0) {
			arr = new T[size];
		}
		cout << "Queue const" << endl;
	}

	~Queue() {
		if(arr != NULL) {
			delete [] arr;
			arr = NULL;
		}
		cout << "Queue dest" << endl;
	}

	bool isFull() {
		if(front == 0 & rear == size -1) 
			return true;
		else
			return false;
	}

	bool isEmpty() {
		if(front == -1 & rear == -1)
			return true;
		else
			return false;
	}

	int isSize() {
		return count;
	}

	//inserting value using enqueue
	void enqueue(T value) {
		if(isFull()) {
			cout << "Queue overflow...!!!, return from here...!!!" << endl;
			return;
		}
		if(front == -1) {
			front = 0;
		} 
		cout << "Insering the value : " << value << endl;
		arr[++rear] = value;
		count++;
	}

	//deleting value using dequeue
	void dequeue() {
		if(isEmpty()) {
			cout << "Queue underflow...!!!, retun from here...!!!" << endl;
			return;
		}

		if(front > rear) {
			front = rear = -1;
			return;
		} 

		cout << "Deleting the value : " << arr[front++] << endl;
		count--;
	}

	void print() {
		if(isEmpty()) {
			cout << "Queue underflow...!!!, retun from here...!!!" << endl;
			return;
		}
		
		for (int i = front; i <= rear; i++) {
			cout << "arr[" << i << "] --> " << arr[i] << endl;
		}
	}
};

int main() {
	Queue<int> q(3);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	cout << "Size of the queue : " << q.isSize() << endl;
	q.print();
	q.enqueue(40);
	q.dequeue();
	q.print();
	cout << "Size of the queue : " << q.isSize() << endl;
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	cout << "Size of the queue : " << q.isSize() << endl;
	
	return 0;
}