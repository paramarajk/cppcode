/*Anagram strings,
example:
hamlet
letham
here both string having the equalent chars*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define MAX 20
#define MAX_CHAR 256

void anagram() {
	char str1[MAX] = { 0 };
	char str2[MAX] = { 0 };
	int count[MAX_CHAR] = { 0 }, i = 0, j = 0, s1_size = 0, s2_size = 0;

	printf("Enter the string1 & string2 1 by 1: \n");
	scanf("%s %s", str1, str2);
	s1_size = strlen(str1);
	s2_size = strlen(str2);

	if (s1_size != s2_size) {
		printf("Strings are not anagram\n");
		return;
	}

	while (str1[i] != '\0') {
		count[str1[i]]++;
		i++;
	}

	i = 0;
	while (str2[i] != '\0') {
		count[str2[i]]--;
		i++;
	}

	i = 0;
	while (i < s1_size) {
		if (count[str1[i]] > 0) {
			printf("Strings are not anagram\n");
			return;
		}
		i++;
	}
	printf("Strings are anagram\n");
}

int main() {
	anagram();
}