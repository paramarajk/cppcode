/*change endianness*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int val = 10;
	int result = 0;
	result |= (val & 0x000000FF) << 24;
	result |= (val & 0x0000FF00) << 8;
	result |= (val & 0x00FF0000) >> 8;
	result |= (val & 0xFF000000) >> 24;
	printf("The value is : %d\n", val);
	printf("The result is : %d\n", result);
	return 0;
}

