#include <stdio.h>
#include <pthread.h>
#include <error.h>
#include <limits.h>
pthread_attr_t tha;

void* pth_func(void* arg) {
	char* msg = (char*)arg;
	int size = PTHREAD_STACK_MIN + 110;
	printf("Before : My message is : %s\n", msg);
	int arr[size];
	int i = 0;
	for (; i < size; i++) {
		arr[i] = i;
	}
	printf("After : My message is : %s\n", msg);
	return;
}

int main() {
	int size = 100;
	size_t s_size;
	pthread_t th1;
	pthread_attr_init(&tha);
	if (pthread_attr_setstacksize(&tha, PTHREAD_STACK_MIN + size) != 0) {
		perror("The error is : ");
	}
	pthread_attr_getstacksize(&tha, &s_size);
	printf("The stack size of th1 is : %d\n", s_size);
	pthread_create(&th1, &tha, pth_func, "hello world");

	pthread_join(th1, NULL);
	pthread_attr_destroy(&tha);
	return 0;
}
