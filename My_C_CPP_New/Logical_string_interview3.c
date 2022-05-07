/*Removing duplication of string*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 20
#define MAX_CHAR 256

void remove_duplicate() {
	char str[MAX] = { 0 };
	int count[MAX_CHAR] = { 0 }, i = 0, pos = 0;
	printf("Enter the string\n");
	scanf("%s", str);


	while (str[i] != '\0') {
		count[str[i]]++;
		if (count[str[i]] == 1) {
			str[pos++] = str[i];
		}
		i++;
	}
	str[pos] = '\0';
	printf("The Modified string is : %s\n", str);
}

int main() {
	remove_duplicate();
	return 0;
}