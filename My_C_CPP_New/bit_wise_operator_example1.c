#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <unistd.h>

#define SYS_BIT 8

void count_ones() {
	int x = 5, check = 1, count = 0;
	int i = 0;

	while (i < SYS_BIT) {
		if (x & check) {
			count++;
			printf("The setting bit is : %d\n", i);
		}
		check = check << 1;
		i++;
	}

	printf("The count is : %d\n", count);
}

void set_bit(int pos) {
	int x = 5, check = 1, i = 0;

	printf("before setting bit at pos : %d value is : %d\n", pos, x);
	while (i < SYS_BIT) {
		if (pos == i) {
			printf("Setting the bit : %d\n", i);
			x = x | check;
		}
		check = check << 1;
		i++;
	}
	printf("after setting bit at pos : %d value is : %d\n", pos, x);
}

void toggle_bit(int pos) {
	int x = 5, check = 1, i = 0;

	printf("before toggle bit at pos : %d value is : %d\n", pos, x);
	while (i < SYS_BIT) {
		if (pos == i) {
			printf("Toggle bit pos id :%d\n", i);
			x = x ^ check;
		}
		check = check << 1;
		i++;
	}
	printf("after toggle bit at pos : %d value is : %d\n", pos, x);
}

void reverse_bits() {
	long x = 5, i = 0, reverse_num = 0;

	printf("The num is : %ld\n", x);
	while (i < SYS_BIT) {
		if (x & (1 << i)) {
			reverse_num |= (1 << ((SYS_BIT - 1) - i));
		}
		i++;
	}
	printf("The revesed number is : %ld\n", reverse_num);
}

int main() {
	count_ones();
	set_bit(5);
	toggle_bit(2);
	reverse_bits();
	return 0;
}

/*output:
The setting bit is : 0
The setting bit is : 2
The count is : 2
before setting bit at pos : 5 value is : 5
Setting the bit : 5
after setting bit at pos : 5 value is : 37
before toggle bit at pos : 2 value is : 5
Toggle bit pos id :2
after toggle bit at pos : 2 value is : 1
The num is : 5
The revesed number is : 160
*/
