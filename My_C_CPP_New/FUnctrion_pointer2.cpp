/*Fucntion pointer*/
#include <iostream>
using namespace std;

typedef int(*FP)(int, int);  //Function pointer declaration

int sum(int x, int y) {
	return x + y;
}

/*function pointer passing as arguments*/
void add(int x, FP fp) {
	cout << "add func : " << x + fp(11, 21) << endl;
}

int main() {
	FP fp = &sum; /*intialization function pointer*/

	cout << fp(100, 200) << endl; /*function pointer call*/
	add(50, &sum); /*function call*/
	return 0;
};

/*
output is :
300
add func : 82
*/
