#ifndef MYSTRING_H
#define MYSTRING_H

int my_strlen(const char* _buffer) {
	int _size = 0;
	while (_buffer[_size] != '\0') {
		++_size;
	}
	return _size;
}

void my_stringcpy(char* dest, const char* src) {
	int i = 0;
	while (*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

#endif // !MYSTRING_H

