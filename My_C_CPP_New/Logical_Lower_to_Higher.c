/*Lower to upper conversion*/
#include <stdio.h>

int main(void) {
	char Val = 'a';
	Val &= ~(1U << 5);
	printf("The value is : %c\n", Val);
	return 0;
}

