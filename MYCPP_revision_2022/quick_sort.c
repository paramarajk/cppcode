
//quick sort

#include <stdio.h>

void print(int *arr, int size) {
	for(int i = 0; i < size; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *arr, int s, int e) {
	int i = s-1, pivot = arr[e];

	for(int j = s; j < e; j++) {
		if(arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[e]);
	return i+1;
}

void quick_sort(int *arr, int s, int e) {
	if(s < e) {
		int p = partition(arr, s, e);
		quick_sort(arr, s, p-1);
		quick_sort(arr, p+1, e);
	}
}

int main() {
	int arr[] = {5,4,3,1,6,9,8};
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("Array befor quick sort\n");
	print(arr, size);
	
	quick_sort(arr, 0, size-1);
	printf("arr , after quick sort\n");
	print(arr, size);



	return 0;
}
