#include<stdio.h>

void reverse_number() {
	int num = 1234;
	int result = 0, rem = 0;

	printf("Num is : %d\n", num);
	while (num != 0) {
		result = (num % 10) + (result * 10);
		num /= 10;
	}
	printf("Reversed number is : %d\n", result);
}

int main() {
	reverse_number();
	return 0;
}