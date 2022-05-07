#include <stdio.h>
#include <string.h>

void str_rev(char* str) {
	int i, j;
	char c;
	for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
		/*c = str[i];
		str[i] = str[j];
		str[j] = c;*/
		str[i] ^= str[j];
		str[j] ^= str[i];
		str[i] ^= str[j];
	}
}

int main() {
	char str[] = "geeks for geeks";
	str_rev(str);
	printf("%s\n", str);
	return 0;
}
