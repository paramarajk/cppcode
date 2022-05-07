/*
Finding the intersection chars from two given strings
example:
input: s1 = "", s2 = "";
output: 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 50
#define MAX_CHAR 256

int count[MAX_CHAR] = { 0 };

void intersection_char(char* str1, char* str2) {
	while (*str1) {	count[*str1++]++; }
		
	while (*str2) {
		if (count[*str2] > 0) {
			printf("%c", *str2);
			count[*str2]--;
		}
		str2++;
	}
	printf('\n');
}

int main() {
	char str1[MAX] = "stroustrup", str2[MAX] = "programmings";
	intersection_char(str1, str2);
	return 0;
}

/*
input :
str1 = "stroustrup", str = "programmings"
output : 
prors
*/