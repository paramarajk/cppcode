/*finding the substring occurence from string*/
#include<stdio.h>
#include <string.h>

void strncmp_func() {
	char* str1 = "Paramaraj rahara";
	char* str2 = "ra";
	
	int size1 = strlen(str1);
	int size2 = strlen(str2);
	int count = 0;

	for (int i = 0; i < size1; i++) {
		if (strncmp(str1+i, str2, size2) == 0) {
			count++;
			i++;
		}
	}

	printf("The count is : %d\n", count);
}

int main() {
	char* str1 = "How are you?, are you fine?, yes, ar you fine";
	char* str2 = "are";
	int size = strlen(str1);
	int count = 0;


	for (int i = 0, j = 0; i < size; i++) {
		if (str1[i] == str2[j]) {
			if (j == strlen(str2) - 1) {
				count++;
				j = 0;
			}
			j++;
		}
		else {
			j = 0;
		}
	}

	printf("The number of occuernece of substring is : %d\n", count);
	strncmp_func();
}