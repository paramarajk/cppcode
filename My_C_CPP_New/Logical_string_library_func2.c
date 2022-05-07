/*strcmp, strncmp impl*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 50

int my_strcmp(char* str1, char* str2) {
	if (str1 == NULL && str2 == NULL) {
		printf("str1 & str2 is null, we cant compare both strings\n");
		return;
	}

	while (*str1) {
		if (*str1++ != *str2++)
			break;
	}
	return *(unsigned char*)str1 - *(unsigned char*)str2;
}

int my_strncmp(char* str1, char* str2, int size) {
	if (str1 == NULL && str2 == NULL) {
		printf("str1 & str2 is null, we cant compare both strings\n");
		return;
	}
	while (size--) {
		if (*str1++ != *str2++)
			break;
	}
	return *(unsigned char*)str1 - *(unsigned char*)str2;
}


// Implement strcmp function in C
int main()
{
	char str1[MAX] = { 0 }, str2[MAX] = { 0 };
	int n = 0;
	printf("Enter string1 & string2\n");
	scanf("%s%s", str1, str2);
	printf("Enter the size to compare\n");
	scanf("%d", &n);

	//int ret = my_strcmp(str1, str2);
	int ret = my_strncmp(str1, str2, n);

	if (ret > 0)
		printf("%s is greater than %s, ret is : %d\n", str1, str2, ret);
	else if (ret < 0)
		printf("%s is less than %s, ret is : %d\n", str1, str2, ret);
	else
		printf("%s is equal to %s, ret is : %d\n", str1, str2, ret);

	return 0;
}