#include <stdio.h>

int main() {
	int num = 12345;
	int res = 0;

	printf("The num is : %d\n", num);
	while (num != 0) {
		res += (num % 10);
		num /= 10;
	}
	printf("Sum of digits : %d\n", res);
}