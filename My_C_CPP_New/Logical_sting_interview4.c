/*Finding unique char*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 20
#define MAX_CHAR 256

void unique_char() {
	char str[MAX] = { 0 };
	int count[MAX_CHAR] = { 0 }, i = 0;
	printf("Enter string\n");
	scanf("%s", str);

	while (str[i] != '\0') {
		count[str[i]]++;
		if (count[str[i]] > 1) {
			printf("%s is not unique\n", str);
			return;
		}
		i++;
	}
	printf("%s is unique\n", str);
}

int main() {
	unique_char();
	return 0;
}


/*
Enter string
abc
abc is unique

*/