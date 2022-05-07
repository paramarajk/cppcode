/*Factorial*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*void fact(int num) {
	int result = 1;
	while (num > 0) {
		result *= num--;
	}
	printf("The factorial is : %d\n", result);
}*/

int fact(int num) {
	if (num == 0 || num == 1)
		return 1;
	else
		return (num * fact(num - 1));
}

int main() {
	int num = 0;
	printf("Enter number: \n");
	scanf("%d", &num);
	printf("The fact of %d is : %d\n", num, fact(num));
	return 0;
}