/*HTC Global Services Interview Question for Software Developers
convert 1st letter of string into Upper caseletter*/

#include <stdio.h>

int main() {
	char str[] = "paramaraj";
	printf("Before converting string : %s\n", str);
	str[0] = str[0] - 32;
	printf("After converting string : %s\n", str);
	return 0;
}

/*output :
Before converting string : paramaraj
After converting string : Paramaraj
*/
