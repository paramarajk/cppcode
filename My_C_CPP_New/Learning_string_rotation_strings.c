/*FInding the rotation of two string
example: 
s1 = "apple";
s2 = "leapp"
here s1 is rotation of s2
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 50

void rotate(char* str) {
	int size = strlen(str), i = 0, j = 0, pos = 0;
	char c = '0';

	c = str[pos];
	while (str[i] != '\0') {
		str[i] = str[i + 1];
		i++;
	}
	str[--i] = c;
	printf("Rotated string is : %s\n", str);
}

void find_rotation(char* s1, char* s2) {
	int i = 0;
	if (strlen(s1) != strlen(s2)) {
		printf("s1 is not rotation of string s2\n");
		return;
	}
	while (s2[i] != '\0') {
		rotate(s2);
		if (strcmp(s1, s2) == 0) {
			printf("s1 is rotation of string of s2\n");
			return;
		}
		i++;
	}
	printf("s1 is not rotation of string s2\n");
}

int main() {
	char str1[MAX] = "apple", str2[MAX] = "leapp";
	//printf("Enter string1 and string2: \n");
	//scanf("%s%s", str1, str2);
	find_rotation(str1, str2);
	return 0;
}
