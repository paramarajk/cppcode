/*
n = 6, 1 + 2 + 3 + 4 + 5 + 6 = 21;
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LIMIT 1000
/*
int sumofnaturalint(int num) {
	if (num != 0)
		return (num + sumofnaturalint(num - 1));
	else
		return 0;
}

int func1(int num) {
	if (num == 1)
		return 0;
	else
		return 1 + func1(num / 2);
}*/

void func2(int num) {
	if (num == 0) return;

	func2(num / 2);
	printf("Retrace from stack\n");
	printf("%d\n", num);
}
/*
void func3(int num) {
	int i = 0;

	if (num > 1) func3(num - 1);

	while (i++ < num) {
		printf("*");
	}
	printf("\n");
}

void func4(int num) {
	if (num <= 0) return;
	if (num > LIMIT) return;
	printf("%d\n", num);
	func4(2 * num);
	printf("return, %d\n", num);
}*/

int main() {
	int num = 0, res;
	printf("Enter the number : \n");
	scanf("%d", &num);

	/*res = sumofnaturalint(num);
	printf("The sum of natural numbers : %d\n", res);

	res = func1(num);
	printf("The sum of natural numbers : %d\n", res);
	*/
	printf("func2\n");
	func2(num);
	/*
	printf("func3\n");
	//func3(num);

	printf("func4\n");
    func4(num);
	*/
	return 0;
}