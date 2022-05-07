/*Finding the unrepated first char from the string 
example: 
input : Paramaraj
output : P
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 20
#define MAX_CHAR 256

int count[MAX_CHAR] = { 0 };

void find_unreapeat_char(char* str) {
	int i = 0;
	while (str[i] != '\0') {
		count[str[i]]++;
		i++;
	}

	i = 0;
	while (str[i] != '\0') {
		if (count[str[i]] == 1) {
			printf("The first unrepated char is : %c\n", str[i]);
			return;
		}
		i++;
	}
}

int main() {
	char str[MAX] = { 0 };
	printf("Enter string\n");
	scanf("%s", str);
	find_unreapeat_char(str);
	return 0;
}