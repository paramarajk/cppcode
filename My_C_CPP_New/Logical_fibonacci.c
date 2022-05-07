/*
series of numbers in which each number ( Fibonacci number ) is the sum of the two preceding numbers.
The simplest is the series 1, 1, 2, 3, 5, 8, etc.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void fibonacci(int num) {
	int a = 0;
	int b = 1;
	int c, i;

	printf("Fibonacci series limit %d\n", num);
	printf("%d <-> %d ", a, b);
	for (i = 2; i < num; i++) {
		c = a + b;
		printf("<-> %d ", c);
		a = b;
		b = c;
	}
	printf("\n");
}

int main() {
	int num;

	printf("Welcome to program for fibonacci\n");
	printf("Enter the limit for fibonacci\n");
	scanf("%d", &num);
	fibonacci(num);
	return 0;
}

/*
output is :
Welcome to program for fibonacci
Enter the limit for fibonacci
15
Fibonacci series limit 15
0 <-> 1 <-> 1 <-> 2 <-> 3 <-> 5 <-> 8 <-> 13 <-> 21 <-> 34 <-> 55 <-> 89 <-> 144 <-> 233 <-> 377
*/
