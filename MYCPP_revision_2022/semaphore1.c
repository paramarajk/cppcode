#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#define MAX 10

static int val = 0;
static int i = 0;
sem_t sem1, sem2;

void* sem_func1(void *args) {
	while(i < MAX) {
		sem_wait(&sem1);
		printf("thread %d, : Value is -> %d\n", pthread_self(), ++val);
		sem_post(&sem2);
		++i;
	}
}

void* sem_func2(void *args) {
	while(i < MAX) {
		sem_wait(&sem2);
		printf("thread %d, : Value is -> %d\n", pthread_self(), ++val);
		sem_post(&sem1);
		++i;
	}
}

int main() {
	sem_init(&sem1, 0, 1);
	sem_init(&sem2, 0, 0);

	pthread_t semt1, semt2;

	pthread_create(&semt1, NULL, sem_func1, NULL);
	pthread_create(&semt2, NULL, sem_func2, NULL);

	pthread_join(semt1, NULL);
	pthread_join(semt2, NULL);

	sem_destroy(&sem1);
	sem_destroy(&sem2);

	return 0;
}