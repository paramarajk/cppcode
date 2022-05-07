#include <stdio.h>

int main() {
	const char* p = "abc";
	const char* q = "abc123";

	while (*p = *q) {
		printf("%c%c\n", *p, *q);
	}
	return 0;
}
