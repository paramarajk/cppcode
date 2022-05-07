#include <stdio.h>
#include <string.h>

void aciitoint(char* str) {
	int res = 0, sign = 1;

	int i = 0;
	if (str[i] == '-') {
		sign = -1;
		i++;
	}
	while (str[i] != '\0') {
		res = res * 10 + str[i++] - '0';
	}
	res = sign * res;
	printf("The int value is : %d\n", res);
}

int main() {
	printf("Welcome to my acii to int program\n");
	aciitoint("-1234");
	aciitoint("123a");
	return 0;
}

/*
output is :
Welcome to my acii to int program
The int value is : -1234
The int value is : 1279
*/

