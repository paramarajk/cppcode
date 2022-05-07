/*Left rotation*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 50

void left_rotate(char* str, int n) {
	int i = 0, j = 0, pos = 0;
	char c = '0';

	while (i < n) {
		c = str[pos];
		
		while (str[j] != '\0') {
			str[j] = str[j + 1];
			j++;
		}
		str[--j] = c;
		i++, j = 0;
	}
	printf("After left rotation : %s\n", str);
}

void right_rotate(char* str, int n, int size) {
	int i = 0, j = 0, pos = size - 1;
	char c = '0';

	while (i < n) {
		c = str[pos];

		j = pos;
		while (j > 0) {
			str[j] = str[j - 1];
			j--;
		}
		str[j] = c;
		i++;
	}
	printf("After right rotation : %s\n", str);
}
int find_t(char* str, char c) {
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] == c) {
			return 1;
		}
		i++;
	}
	return 0;
}

void pos_rotate(char* str, int size, int n) {
	char* token = NULL;

	printf("Before pos-rotate : %s\n", str);
	token = strtok(str, " ");
	while (token != NULL) {
		if (find_t(token, 't')) {
			right_rotate(token, n, strlen(token));
		}
		else {
			int i = 0;
			while (token[i] != '\0') {
				token[i++] = '*';
			}
		}
		token = strtok(NULL, " ");
	}

	int i = 0;
	while (i < size) {
		if (str[i] == '\0') {
			str[i] = ' ';
		}
		i++;
	}
	printf("After pos-rotate : %s\n", str);
}

int main() {
	char str[MAX] = { 0 };
	char str1[] = "get it right first time display";
	int size = 0, n = 0, ch = 0, size1 = 0;
	printf("Enter string to rotate\n");
	scanf("%[^\t\n]s", str);
	printf("Enter no of rotation\n");
	scanf("%d", &n);
	printf("Enter choice for left/right/pos_rotate rotation: 0/1/2\n");
	scanf("%d", &ch);

	size = strlen(str);
	size1 = strlen(str1);
	if (ch == 0) 
		left_rotate(str1, n);
	else if(ch == 1)
		right_rotate(str1, n, size);
	else /*3 position rotate string right when its having 't' or replace string with none , asked in opentext*/
		pos_rotate(str1, size, n);
	return 0;
}