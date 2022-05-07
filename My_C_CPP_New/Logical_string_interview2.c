/*sub string replacement*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define MAX 10

int main() {
	char str[MAX];
	char r_str[MAX];
	char f_str[MAX];
	printf("Enter the string\n");
	scanf("%s", str);
	printf("Enter find string\n");
	scanf("%s", f_str);
	printf("Enter the replace str :\n");
	scanf("%s", r_str);
	int size = strlen(str), pos = 0;
	int r_size = strlen(r_str), f_size = strlen(f_str);
	//printf("Sizeof the string is : %d\n", size);

	/*Finding the string ll and replace to aa*/
	for (int i = 0, j = 0; i < size; i++) {
		if (j == 0) pos = i;
		if (str[i] == f_str[j]) {
			if (j == f_size - 1) {
				/*ll , aa*/
				if (r_size == f_size) {
					int k = 0;
					while (k < strlen(r_str)) {
						str[pos++] = r_str[k++];
					}
				}
				/*ll, a*/
				else if (r_size < f_size) {
					int k = 0, d_pos = 0;
					while (k < r_size) {
						str[pos++] = r_str[k++];
					}
					d_pos = pos + (f_size - r_size);
					while (str[d_pos] != '\0') {
						str[pos++] = str[d_pos++];
					}
					str[pos] = '\0';
				}
				/*ll, aaa*/
				else if (r_size > f_size) {
					int m_pos = pos + (r_size - 1);
					int k = size;
					str[k + 1] = '\0';
					k--;
					while (k >= m_pos) {
						str[k + 1] = str[k--];
					}
					k = 0;
					while (k < r_size) {
						str[pos++] = r_str[k++];
					}
				}
			}
			if (f_size > 1) {
				j++;
			}
			else {
				j = 0;
			}
		}
		else {
			j = 0;
		}
	}
	printf("The replaced string is : %s\n", str);
	return 0;
}
