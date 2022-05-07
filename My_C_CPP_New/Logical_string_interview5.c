/*Find the count of char from string
geeks
g = 1
e = 2
k = 1
s = 1
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX 50
#define MAX_CHAR 256

void count_char() {
	char str[MAX] = { 0 };
	int count[MAX_CHAR] = { 0 }, i = 0;

	printf("Enter string\n");
	scanf("%s", str);
	while (str[i] != '\0') {
		count[str[i]]++;
		i++;
	}

	i = 0;
	while (str[i] != '\0') {
		if (count[str[i]] > 0) {
			printf("count of char : %c is : %d\n", str[i], count[str[i]]);
			count[str[i]] = 0;
		}
		i++;
	}
}

int main() {
	count_char();
}