/*permutation parentheses
example: 
input : n = 1
output : {}
input : n = 2
output :
{}{}
{{}}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100

void permutation_parentheses(int pos, int n, int open, int close) {
	static char str[MAX] = { 0 };
	if (close == n) {
		printf("%s\n", str);
		return;
	}
	else {
		if (open > close) {
			str[pos] = '}';
			permutation_parentheses(pos + 1, n, open, close + 1);
		}
		if (open < n) {
			str[pos] = '{';
			permutation_parentheses(pos + 1, n, open + 1, close);
		}
	}
}

int main() {
	int n = 0, pos = 0, open = 0, close = 0;
	printf("Enter number of permutation parentheses\n");
	scanf("%d", &n);

	if (n > 0) {
		permutation_parentheses(pos, n, open, close);
	}
	return 0;
}
