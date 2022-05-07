/*palindrome with ignoring the case*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define MAX 20

void palindrome(char* str) {
	int l = 0, h = strlen(str)-1;

	while (h > l) {
		if (str[l] > str[h]) {
			if (str[l] != str[h]+32) {
				printf("%s, not a palindrome\n", str);
				return;
			}
		}
		else if(str[l] < str[h]) {
			if (str[l]+32 != str[h]) {
				printf("%s, not a palindrome\n", str);
				return;
			}
		}
		else {
			if (str[l] != str[h]) {
				printf("%s, not a palindrome\n", str);
				return;
			}
		}
		l++, h--;
	}
	printf("%s, is a palindrome\n", str);
}

int main() {
	char str[MAX] = { 0 };
	printf("Enter string\n");
	scanf("%s", str);
	palindrome(str);
	return 0;
}
