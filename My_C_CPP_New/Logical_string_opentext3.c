/*Rotation of string*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 50

void rotate(char* str, int size) {
	char temp[MAX] = { 0 };
	int i = 0;

	while (i < size) {
		int j = i;
		int k = 0;

		//copy the content from str to temp buffer
		while (str[j] != '\0') {
			temp[k++] = str[j++];
		}

		j = 0;
		while (j < i) {
			temp[k++] = str[j++];
		}
		i++;
	}
	printf("string is : %s\n", temp);
}

//Efficient way of rotate
void rotate1(char *str, int len) {
	char c = str[len];
	while (len > 0) {
		str[len] = str[len - 1];
		len--;
	}
	str[len] = c;
	//printf("%s\n", str);
}


//left rotation
void left_rotate(char* str, int num) {
	while (num > 0) {
		int len = strlen(str) - 1;
		rotate1(str, len);
		num--;
	}
	printf("%s\n", str);
}

void rotate2(char* str) {
	char c = str[0];
	int i = 0;
	while (str[i] != '\0') {
		str[i] = str[i + 1];
		i++;
	}
	str[--i] = c;
}

void right_rotate(char* str, int num) {
	while (num > 0) {
		rotate2(str);
		num--;
	}
	printf("%s\n", str);
}
int main() {
	char str[MAX] = { 0 };
	int size = 0;
	printf("Enter string\n");
	scanf("%s", str);
	size = strlen(str);
	//rotate1(str, size-1);
	//left_rotate(str, 3);
	right_rotate(str, 3);
	return 0;
}


/*
output:
Enter string
apple
string is : eappl
*/