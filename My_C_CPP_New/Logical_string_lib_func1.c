/*strcpy, strncpy, strlen and memcpy impl*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 50

int my_strlen(char* str) {
	int i = 0;
	while (str[++i] != '\0');
	return i;
}

void my_strcpy(const char* src, char* dst) {
	if (src == NULL) {
		printf("src is null, we cant go further, terminating cpy,\n");
		return;
	}
	while (*src) {
		*dst++ = *src++;
	}
	*dst = '\0';
}

void my_strncpy(const char* src, char* dst, int size) {
	if (dst == NULL) {
		printf("src is null, we cant go further, terminating cpy,\n");
		return;
	}
	while (*src && size--) {
		*dst++ = *src++;
	}
	*dst = '\0';
}

void my_strcat(char* src1, char* src2) {
	if (src1 == NULL || src2 == NULL) {
		printf("src is null, we cant go further, terminating cpy,\n");
		return;
	}

	char* ptr = src1 + my_strlen(src1);
	while (*src2) {
		*ptr++ = *src2++;
	}
	*ptr = '\0';
}

void my_strncat(char* src1, char* src2, int size) {
	if (src1 == NULL || src2 == NULL) {
		printf("src is null, we cant go further, terminating cpy,\n");
		return;
	}

	char* ptr = src1 + my_strlen(src1);
	while (*src2 && size--) {
		*ptr++ = *src2++;
	}
	*ptr = '\0';
}

int main() {
	char src[MAX] = { 0 }, dst[MAX] = { 0 };
	int n = 0;
	printf("Enter string\n");
	scanf("%s", src);
	printf("Enter number of strings need to be copied using the stncpy\n");
	scanf("%d", &n);
	int size = my_strlen(src);
	
	printf("The length of ther string is : %d\n", size);
	my_strcpy(src, dst);
	printf("The string after strcpy, dst : %s\n", dst);
	my_strncpy(src, dst, n);
	printf("The string after strncpy, dst : %s\n", dst);
	my_strcat(dst, src);
	printf("The string after strcat, dst : %s\n", dst);
	my_strncat(dst, src, n);
	printf("The string after strncat, dst : %s\n", dst);
	return 0;
}