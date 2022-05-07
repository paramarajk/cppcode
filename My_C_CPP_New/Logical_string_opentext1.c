/*Balanced parentheses*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 50
static char arr[MAX] = { 0 };

char findopen(char str) {
	if (str == '}')
		return '{';
	else if (str == ']')
		return '[';
	else if (str == ')')
		return '(';
	else
		return '0';
}

int check(char* str, int n) {
	int i = 0, top = -1;
	char open;

	if (n == 0 || n == 1) return 0;
	
	while (str[i] != '\0') {
		if (str[i] == '{' || str[i] == '(' || str[i] == '[') {
			top++;
			arr[top] = str[i];
		}
		else if (str[i] == '}' || str[i] == ']' || str[i] == ')') {
			open = findopen(str[i]);
			if (arr[top] == open) {
				arr[top] = '0';
				top--;
			}
			else {
				return 0;
			}
		}
		i++;
	}
	if (top == -1)
		return 1;
	else
		return 0;
}


int main()
{
	char str[MAX] = {0};
	printf("Enter expression:\n");
	scanf("%s", str);
	int n = strlen(str);
	if (check(str, n))
		printf("Balanced\n");
	else
		printf("Not Balanced\n");
	return 0;
}