#include <stdio.h>
#include <stdlib.h>

#define ROW 2
#define COL 3

void twodarray() {
	int **arr = NULL;
	
	//allocating memory for row
	arr = (int **)malloc(ROW * sizeof(int));

	//allocating memory for col
	for(int i = 0; i < ROW; i++) {
		*(arr + i) = (int *)malloc(COL * sizeof(int));
	}

	//Setting values in array
	int count = 1;
	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			*(*(arr + i)+j) = count++;
		}
	}

	//Display the 2d array values 
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			printf("Arr[%d][%d] = %d\n", i, j, *(*(arr+i) + j));
		}
	}


	//clear the memory
	for(int i = 0; i < ROW; i++) {
		free(*(arr + i));
	}

	free(arr);
}

int main() {
	twodarray();
	return 0;
}