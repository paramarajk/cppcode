#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX 10

pthread_mutex_t mu, mu1;
int val = 0;

void* thread_func(void* arg) {
	while (val < MAX) {
		pthread_mutex_lock(&mu);
		printf("T1: The val is : %d\n", ++val);
		pthread_mutex_unlock(&mu);
	}
}
void* thread_func1(void* arg) {
	while (val < MAX) {
		pthread_mutex_lock(&mu1);
		printf("T2: The val is : %d\n", ++val);
		pthread_mutex_unlock(&mu1);
	}
}

int main() {
	pthread_t th1, th2;
	pthread_mutex_init(&mu, NULL);
	pthread_mutex_init(&mu1, NULL);
	pthread_create(&th1, NULL, thread_func, NULL);
	pthread_create(&th2, NULL, thread_func1, NULL);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	pthread_mutex_destroy(&mu);
	pthread_mutex_destroy(&mu1);
	return 0;
}
