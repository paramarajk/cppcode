/*Memcpy impl
Prototype : void *memcpy(void *dest, conat void *src, int num);

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 20

void my_memcpy(void* dest, const void* src, int size) {
	char* d = (char*)dest;
	char* s = (char*)src;

	while (size-- > 0) {
		*d++ = *s++;
	}
	*d = '\0';
}

int my_memcmp(const void* str1, const void* str2, int size) {
	char* s1 = (char*)str1;
	char* s2 = (char*)str2;

	while (size-- > 0) {
		if (*s1++ != *s2++) {
			return s1[-1] < s2[-1] ? -1 : 1;
		}
	}
	return 0;
}

void my_memset(int *ptr, int val, int size) {
	//char* p = ptr;
	while (size-- > 0) {
		*ptr++ = val;
	}
	//return p;
}

int main() {
	char str[MAX] = { 0 }, dest[MAX] = { 0 };
	int num = 0, arr[MAX];
	
	printf("Enter string\n");
	scanf("%s", str);
	printf("Enter no of string to be copied\n");
	scanf("%d", &num);

	my_memcpy(dest, str, num);
	printf("The copied string is, dest : %s\n", dest);

	int ret = my_memcmp(str, dest, strlen(str));
	if (ret > 0) {
		printf("src is greater than dest\0");
	}
	else if (ret < 0) {
		printf("src is lessthan dest\n");
	}
	else {
		printf("src is equal to dest\n");
	}

	my_memset(arr, 0, MAX);
	printf("After memset array : \n");
	int i = 0;
	while (i < MAX) {
		printf("%d\t", arr[i++]);
	}
	printf("\n");
	return 0;
}