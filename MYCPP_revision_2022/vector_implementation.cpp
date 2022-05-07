#include <iostream>
#include <string.h>

using namespace std;

template <typename T>
class myvec{
	T *_buffer;
	unsigned int _size, _capacity;
public:
	typedef T* iterator;
	myvec() : _buffer(NULL), _size(0), _capacity(0) {
		cout << "myvec const with 0 arg" << endl;
	}

	myvec(unsigned int size) : _size(size), _capacity(size) {
		_buffer = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			_buffer[i] = 0;
		}
		cout << "myvec const with 1 arg" << endl;
	}

	myvec(unsigned int size, T&& value) : _size(size), _capacity(size) {
		_buffer = new T[_size];
		for(unsigned int i = 0; i < _size; i++) {
			_buffer[i] = value;
		}
		cout << "myvec const with 2 arg" << endl;
	}

	~myvec() {
		_size = 0;
		_capacity = 0;
		if (_buffer != NULL) {
			delete [] _buffer;
			_buffer = NULL;
		}
		cout << "myvec dest called" << endl;
	}

	myvec(const myvec<T> &obj) {
		_size = obj._size;
		_capacity = obj._capacity;
		if (_buffer != NULL) {
			delete [] _buffer;
			_buffer = NULL;
		}
		_buffer = new T[_size];
		for(unsigned int i = 0; i < _size; i++) {
			_buffer[i] = obj._buffer[i];
		}
		cout << "myvec copy ctor" << endl;
	}

	myvec<T>& operator=(const myvec<T> &obj) {
		if (this != &obj) {
			_size = obj._size;
			_capacity = obj._capacity;
			if (_buffer != NULL) {
				delete [] _buffer;
				_buffer = NULL;	
			}
			_buffer = new T[_size];
			for(unsigned int i = 0; i < _size; i++) {
				_buffer[i] = obj._buffer[i];
			}
			cout << "myvec assignment operator" << endl;
			return *this;
		}
	}

	void myvec_clear() {
		_size = 0;
		_capacity = 0;
		if(_buffer != NULL) {
			delete [] _buffer;
			_buffer = NULL;
		}
	}


	T& myvec_front() {
		return _buffer[0];
	}

	T& myvec_back() {
		return _buffer[_size];
	}

	T& operator[] (unsigned int index) {
		if (index < _size) {
			return _buffer[index];
		} else {
			cout << "Index is out of vector boundry" << endl;
		}
	}

	unsigned int myvec_size() {
		return _size;
	}

	unsigned int myvec_capacity() {
		return _capacity;
	}


	myvec<T>::iterator myvec_begin() {
		return _buffer;
	}

	myvec<T>::iterator myvec_end() {
		return _buffer + _size;
	}

	void myvec_pop_back() {
		_buffer[_size] = 0;
		_size--;
	}

	void myvec_reserve(unsigned int capacity, T value) {
		T *_new_buffer = new T[capacity];

		for (unsigned int i = 0; i < _size; i++) {
			_new_buffer[i] = _buffer[i];
		}
		_new_buffer[_size] = value;

	 	delete [] _buffer;
	 	_buffer = NULL;
	 	_buffer = _new_buffer;
	 	_capacity = capacity;
	}

	void myvec_push_back(T value) {
		if (_size > _capacity) {
			myvec_reserve(_size + _capacity, value);
		} else {
			_buffer[_size] = value;
		}
	}

};

void print() {
}

int main() {
	myvec<int> mv(5, 10);
	myvec<int>::iterator it = mv.myvec_begin();
	mv.myvec_push_back(20);
	it = mv.myvec_begin();
	for(it = mv.myvec_begin(); it != mv.myvec_end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
	return 0;
}