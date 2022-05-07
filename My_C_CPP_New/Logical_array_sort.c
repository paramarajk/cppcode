#include <stdio.h>
#define SIZE 10


int main() {
	int arr[SIZE] = { 1,0,1,0,0,0,1,1,0,1 };
	for (int i = 0, j = SIZE -1 ; i < SIZE; i++, j--) {
		if (arr[i] % 2 == 1 && arr[j] % 2 == 0) {
			arr[i] ^= arr[j];
			arr[j] ^= arr[i];
			arr[i] ^= arr[j];
		}
		else if (arr[i] % 2 == 0 && arr[j] % 2 == 0) {
			j = j + 1;
		}
		else if (arr[i] % 2 == 1 && arr[j] % 2 == 1) {
			//printf("Arr[%d] : %d\n", i, arr[i]);
			i = i - 1;
			//break;
		}
	}

	int i = 0;
	while (i < SIZE) {
		printf("%d\t", arr[i++]);
	}
	printf("\n");
}

/*
Output: 
1       1       1       1       1       0       0       0       0       0
*/