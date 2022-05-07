/*
Prime number logic: a number is prime if it is divisible only by one and itself.
Remember two is the only even and the smallest prime number. First few prime numbers are 1, 2, 3, 5, 7, 11, 13, 17, ....
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int flag = 0, i, j, num;

	printf("Please enter the number\n");
	scanf("%d", &num);

	printf("Prime numbers between 0 to %d is listed below\n", num);
	for (j = 1; j <= num; j++) {
		flag = 0;
		for (i = 1; i <= num; i++) {
			/*printf("j value is : %d, i value is : %d\n", j, i);*/
			
			if (j % i == 0) {
				flag++;
				if (j == 1) flag++;
				/*printf("The flag value is : %d\n", flag);*/
			}

		}
		if (flag == 2) {
			printf("%d\t", j);
		}
	}
	printf("\n");

}

/*
output is :
Please enter the number
100
Prime numbers between 0 to 100 is listed below
2       3       5       7       11      13      17      19      23      29      31      37      41      43      47      53      59      61      67      71      73      79      83      89      97
*/
