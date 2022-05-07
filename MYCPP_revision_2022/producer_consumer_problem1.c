#include <stdio.h>
#include <pthread.h>

#define MAX 10
pthread_mutex_t t_mutex;
pthread_cond_t condc;
pthread_cond_t condp;
static int i = 0;
int buffer = 0;

void* consumer(void *ptr) {
	for(; i <= MAX; i++) {
		pthread_mutex_lock(&t_mutex);
		while(buffer == 0) {
			pthread_cond_wait(&condc, &t_mutex);
		}
		printf("Consumer: consume the item : %d\n", i);
		buffer = 0;
		pthread_cond_signal(&condp);
		pthread_mutex_unlock(&t_mutex);
	}
	pthread_exit(0);
}

void* producer(void *ptr) {
	for(; i <= MAX; i++) {
		pthread_mutex_lock(&t_mutex);
		while(buffer != 0) {
			pthread_cond_wait(&condp, &t_mutex);
		}
		buffer = 1;
		printf("Producer: Produce the item : %d\n", i);
		pthread_cond_signal(&condc);
		pthread_mutex_unlock(&t_mutex);
	}
	pthread_exit(0);
}

int main() {
	pthread_t cons, prod;

	//Intializing mutex & cond 
	pthread_cond_init(&condp, NULL);
	pthread_cond_init(&condc, NULL);
	pthread_mutex_init(&t_mutex, NULL);

	//Creating therad
	pthread_create(&cons, NULL, consumer, NULL);
	pthread_create(&prod, NULL, producer, NULL);

	pthread_join(cons, NULL);
	pthread_join(prod, NULL);

	//Destroy mutex & cond
	pthread_cond_destroy(&condp);
	pthread_cond_destroy(&condc);
	pthread_mutex_destroy(&t_mutex);

	return 0;
}