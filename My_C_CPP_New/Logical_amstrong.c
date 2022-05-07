/*Amstrong number is :
for exapmle number is : 153 ,its having 3 digits,
so that reason i am calulating : 1 ^3 + 5 ^ 3 + 3 ^ 3 = 1 + 125 + 27 = 153 ,
the sum of the digits ^ 3 is equal to actual number, so that its called : amstrong number.*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int power(int num, int digit) {
	int i, res = 1;
	for (i = 0; i < digit; i++) {
		res = res * num;
	}

	return res;
}

int main() {
	int num, temp, rem = 0, sum = 0, digits = 0;

	printf("Please enter the number to verify amstrong number or not? \n");
	scanf("%d", &num);

	/*counting no of digits*/
	temp = num;

	while (temp != 0) {
		digits++;
		temp = temp / 10;
	}


	/*Checking Amstrong*/
	temp = num;
	while (temp != 0) {
		rem = temp % 10;
		sum = sum + power(rem, digits);
		temp = temp / 10;
	}

	if (sum == num)
		printf("Entered number %d is Amstrong number\n", num);
	else
		printf("Entered number %d is not Amstrong number\n", num);
}


/*
output is :

Please enter the number to verify amstrong number or not?
10
Entered number 10 is not Amstrong number

Please enter the number to verify amstrong number or not?
153
Entered number 153 is Amstrong number
*/
