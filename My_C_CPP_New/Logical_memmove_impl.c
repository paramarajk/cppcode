//google interview
#include <stdio.h>
#include <string.h>

void* memove(void* dest, void* src, size_t n) {
	char* d = (char*)dest;
	char* s = (char*)src;

	if (s == d)
		return dest;

	if (s < d) {
		//copy from back 
		s = s + n - 1;
		d = d + n - 1;
		while (n--) {
			*d-- = *s--;
		}
	}
	else {
		//copy from front 
		while (n--)
			* d++ = *s++;
	}
	return dest;
}

int main() {
	char src[100] = "geeks for";
	memove(src + 5, src, strlen(src));
	printf("%s\n", src);
	return 0;
}
