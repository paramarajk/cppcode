#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int gval = 0;

void* thread_func1(void *arg) {
	int i = 0;
	while(i < 5) {
		printf("thread_func1...., Gval : %d\n", gval++);
		i++;
	}
	pthread_exit(0);
}

void* thread_func2(void *arg) {
	int i = 0;
	while(i < 5) {
		printf("thread_func2...., Gval : %d\n", gval++);
		i++;
	}
	pthread_exit(0);
}

int main() {
	pthread_t th1, th2;
	pthread_create(&th1, NULL, thread_func1, NULL);
	pthread_create(&th2, NULL, thread_func2, NULL);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	return 0;
}
