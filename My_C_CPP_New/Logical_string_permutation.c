/*Permutation : */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10

void swap(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

void permutation(a, s, e) {
	if (s == e) {
		printf("%s\n", a);
	}
	else {
		for (int i = s; i <= e; i++) {
			swap(a + s, a + i);
			permutation(a, s + 1, e);
			swap(a + s, a + i);  //retrace
		}
	}
}
int main() {
	char str[MAX] = { 0 };
	int size = 0;

	printf("Enter string\n");
	scanf("%s", str);
	size = strlen(str) - 1;
	permutation(str, 0, size);
	return 0;
}