/*swap nibbles*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int val = 17;
	int result = 0;
	result |= (val & 0x0000000F) << 4;
	result |= (val & 0x000000F0) >> 4;
	printf("The value is : %d\n", val);
	printf("The result is : %d\n", result);
	return 0;
}

