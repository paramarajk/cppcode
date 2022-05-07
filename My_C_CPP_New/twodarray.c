#include <stdio.h>
#include <stdlib.h>
#define ROW 2
#define COL 3

void twodarr() {
	int** arr;
	//allocating memory
	arr = (int**)malloc(ROW * sizeof(int*)); //allocating memory for row

	for (int i = 0; i < ROW; i++) {
		*(arr + i) = (int*)malloc(COL * sizeof(int)); //allocating memory for colom
	}

	//Filling the values in index
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			*(*(arr + i) + j) = i + j;
		}
	}

	//Printing the values from array index
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			printf("arr[%d][%d] = %d\n", i, j, *(*(arr + i) + j));
		}
	}

	//deleting the array
	for (int i = 0; i < ROW; i++) {
		free(*(arr + i));
	}
	free(arr);
}

int main() {
	twodarr();
	return 0;
}
