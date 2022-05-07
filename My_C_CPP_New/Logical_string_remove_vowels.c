/* Removinlg the vowles from string
input : HAIhow
output : Hhw*/

#include <stdio.h>
#define MAX_CHAR 256
int count[MAX_CHAR] = { 0 };

void remove_vowles(char* str, char* v) {
	while (*v != '\0') {
		count[*v++]++;
	}

	int i = 0, j = 0;
	while (str[i] != '\0') {
		if (count[str[i]] == 0) {
			str[j++] = str[i];
		}
		i++;
	}
	str[j] = '\0';
}
int main() {
	char str[] = "HAIhow";
	char vowles[] = "aeiouAEIOU";
	printf("Before removing vowles : %s\n", str);
	remove_vowles(str, vowles);
	printf("After removing vowles : %s\n", str);
	return 0;
}


