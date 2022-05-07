#include <stdio.h>
#include <string.h>

#define MAX 10

void rotate(char *str) {
	int i = 0, pos = 0;
	char c = '0';

	c = str[pos];
	while(str[i] != '\0') {
		str[i] = str[i+1];
		i++;
	}
	str[--i] = c;
	printf("Rotated string : %s\n", str);
}

void find_rotation(char *str1, char *str2) {
	if (strlen(str1) != strlen(str2)) {
		printf("S1 is not rotation of S2\n");
		return;
	}

	int i = 0;
	while(str2[i] != '\0') {
		rotate(str2);
		if (strcmp(str1, str2) == 0) {
			printf("S1 is rotation of S2\n");
			return;
		}
		i++;
	}
	printf("S1 is not rotation of S2\n");
}
int main() {
	char str1[MAX] = "apple", str2[MAX] = "pleap";
	printf("String 1 is : %s\n", str1);
	printf("String 2 is : %s\n", str2);
	find_rotation(str1, str2);

	return 0;
}
