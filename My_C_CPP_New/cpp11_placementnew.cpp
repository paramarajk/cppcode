#include <iostream>
using namespace std;

int main() {
	//buf on stack
	char buffer[sizeof(int) * 2];
	cout << "sizeof(buffer) : " << sizeof(buffer) << endl;

	//placement new 
	//new (address) (type) intializer
	int* p = new (buffer) int(3);
	int* q = new (buffer + sizeof(int)) int(5);

	//accessing data from buffer
	int* pbuf = (int*)(buffer + 0);
	int* qbuf = (int*)(buffer + sizeof(int));
	cout << *pbuf << endl;
	cout << *qbuf << endl;
	return 0;
}
