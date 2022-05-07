#include <iostream>
#include <string.h>
using namespace std;

template <typename T>
class myvec {
	T* _buffer;
	unsigned int _size, _capacity;

public:
	typedef T* iterator;
	myvec() {
		_buffer = NULL;
		_size = 0;
		_capacity = 0;
		cout << "myvec default ctor" << endl;
	}

	myvec(unsigned int size) : _size(size), _capacity(size) {
		_buffer = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			_buffer[i] = 0;
		}
		cout << "myvec 1 arg ctor" << endl;
	}

	myvec(unsigned int size, T&& value) : _size(size), _capacity(size) {
		_buffer = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			_buffer[i] = value;
		}
		cout << "myvec 2 arg ctor" << endl;
	}

	~myvec() {
		if (_buffer != NULL) {
			delete[] _buffer;
			_buffer = NULL;
			cout << "myvec dtor" << endl;
		}
	}

	void clear() {
		if (_buffer != NULL) {
			for (unsigned int i = 0; i < _size; i++) {
				_buffer[i] = 0;
			}
			_size = 0;
			_capacity = 0;
		}
	}

	myvec(const myvec<T>& obj) {
		_size = obj._size;
		_capacity = obj._capacity;
		if (_buffer != NULL) {
			delete[] _buffer;
			_buffer = NULL;
		}
		_buffer = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			_buffer[i] = obj._buffer[i];
		}
		cout << "myvec copy ctor" << endl;
	}

	myvec<T>& operator=(const myvec<T>& obj) {
		if (this != &obj) {
			_size = obj._size;
			_capacity = obj._capacity;
			if (_buffer != NULL) {
				delete[] _buffer;
				_buffer = NULL;
			}
			_buffer = new T[_size];
			for (unsigned int i = 0; i < _size; i++) {
				_buffer[i] = obj._buffer[i];
			}
			cout << "myvec assignment operator" << endl;
		}
		return *this;
	}

	unsigned int my_size() {
		return _size;
	}

	unsigned int my_capacity() {
		return _capacity;
	}

	T& my_front() {
		return _buffer[0];
	}

	T& my_back() {
		return _buffer[_size];
	}

	T& operator[] (unsigned int index){
		if (index < _size) {
			return _buffer[index];
		}
		else {
			cout << "index is out of bound" << endl;
		}
	}

	myvec<T>::iterator begin() {
		return _buffer;
	}

	myvec<T>::iterator end() {
		return _buffer + _size;
	}

	void pop_back() {
		_buffer[_size] = 0;
		_size--;
	}

	void reserve(unsigned int capacity, T value) {
		T* _new_buffer = new T[capacity];
		
		for (unsigned int i = 0; i < capacity; i++) {
			if (i == _size) {
				_new_buffer[i] = value;
				break;
			}
			_new_buffer[i] = _buffer[i];
		}

		delete [] _buffer;
		_buffer = NULL;
		_buffer = _new_buffer;
		_capacity = capacity;
	}

	void push_back(T value) {
		if (_size >= _capacity) {
			reserve(_size + _capacity, value);
		}
		else {
			_buffer[_size++] = value;
		}

	}
};

int main() {
	myvec<int> mv(5, 10);
	myvec<int>::iterator it = mv.begin();
	mv.push_back(100);
	mv.push_back(200);
	mv.push_back(300);

	for (auto i : mv)
		cout << "Vec : " << i << endl;


	return 0;
}