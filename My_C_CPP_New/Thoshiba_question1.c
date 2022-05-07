#include <stdio.h>

int main() {
	fork();
	fork();
	fork();
	printf("In main\n");
	return 0;
}