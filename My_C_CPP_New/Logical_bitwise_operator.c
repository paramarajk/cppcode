#include <stdio.h>

void set_bit(int val, int pos) {
	printf("Before setting bit value is : %d\n", val);
	val |= (1U << pos);
	printf("After setting bit value is : %d\n", val);
}

void clear_bit(int val, int pos) {
	printf("Before clearing bit value is : %d\n", val);
	val &= ~(1U << pos);
	printf("After clearing bit value is : %d\n", val);
}

void toggle_bit(int val, int pos) {
	printf("Befor toggle bit value is : %d\n", val);
	val ^= (1U << pos);
	printf("After toggle bit value is : %d\n", val);
}

void get_bit_ith_pos(int val, int pos) {
	printf("Value is : %d\n", val);
	int bit_val = (val &= (1U << pos)) >> pos;
	printf("Bit val is : %d\n", bit_val);
}

void clearing_MSB_bit_from_ith_pos(int val, int pos) {
	printf("Vale is : %d\n", val);
	int bit_val = (val &= (1U << (pos + 1)) - 1);
	printf("Bit val is : %d\n", bit_val);
}

void clearing_LSB_bit_from_ith_pos(int val, int pos) {
	printf("Vale is : %d\n", val);
	int bit_val = (val &= ~((1U << (pos + 1)) - 1));
	printf("Bit val is : %d\n", bit_val);
}

void multiply_with2(int val) {
	printf("Value is : %d\n", val);
	int bit_val = val << 1;
	printf("bit_val is : %d\n", bit_val);
}

void divide_with2(int val) {
	printf("Value is : %d\n", val);
	int bit_val = val >> 1;
	printf("bit_val is : %d\n", bit_val);
}

void little_big_endian() {
	int val = 10;
	char* ptr = (char*)& val;
	if (*ptr == 10) {
		printf("Little endian\n");
	}
	else {
		printf("Big endian\n");
	}
}

void swap_bits_ith_jth() {
	int val = 10;
	int ipos = 2, jpos = 4;
	printf("befor swap, val is : %d\n", val);
	int bit_val1 = (val & (1U << ipos)) >> ipos;
	int bit_val2 = (val & (1U << jpos)) >> jpos;
	if (bit_val1 != bit_val2) {
		val ^= (1U << ipos);
		val ^= (1U << jpos);
	}
	printf("After swap, val is : %d\n", val);
}

void rotate_bits_with_pos() {
	int val = 138;
	int pos = 34;
	int INT_BITS = 28;
	printf("Value is : %d\n", val);
	int bit_val = (val << pos) | (val >> INT_BITS - pos);
	printf("After rotation bit_val : %d\n", bit_val);
}

void lower_to_upper() {
	char val = 'a';
	printf("char is : %c\n", val);
	val &= ~(1U << 5);
	printf("Char is : %c\n", val);
}

void higher_to_lower() {
	char val = 'Z';
	printf("Char is : %c\n", val);
	val |= (1U << 5);
	printf("char is : %c\n", val);
}

int main() {
	printf("SET BIT\n");
	set_bit(10, 4);
	printf("CLEAR BIT\n");
	clear_bit(10, 3);
	printf("TOGGLE BIT\n");
	toggle_bit(10, 5);
	printf("GETTING BIT ith POS\n");
	get_bit_ith_pos(10, 3);
	printf("CLEARING MSB_BITS FROM ith POS\n");
	clearing_MSB_bit_from_ith_pos(10, 1);
	printf("CLEARING LSB_BITS FROM ith POS\n");
	clearing_LSB_bit_from_ith_pos(10, 3);
	printf("MULTIPLY WITH 2\n");
	multiply_with2(10);
	printf("DIVIDE WITH 2\n");
	divide_with2(10);
	printf("CHECKING MACHINE LITTLE/BIG ENDIAN\n");
	little_big_endian();
	printf("SWAPING BITS ith AND jth POS\n");
	swap_bits_ith_jth();
	printf("ROTATE BITS\n");
	rotate_bits_with_pos();
	printf("LOWER TO UPPER\n");
	lower_to_upper();
	printf("HIGHER TO LOWER\n");
	higher_to_lower();
	return 0;
}


