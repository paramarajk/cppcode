#include <stdio.h>
#include <pthread.h>

#define MAX 10
pthread_cond_t cond_c, cond_p;
pthread_mutex_t mu;
const char* _buffer = NULL;

void* producer(void* arg) {
	int i = 0;
	for (; i < MAX; i++) {
		pthread_mutex_lock(&mu);
		while (_buffer != NULL) {
			pthread_cond_wait(&cond_p, &mu);
		}
		_buffer = "Hi";
		printf("Filled Buffer\n");
		pthread_cond_signal(&cond_c);
		pthread_mutex_unlock(&mu);
	}
	pthread_exit(0);
}

void* consumer(void* arg) {
	int i = 0;
	for (; i < MAX; ++i) {
		pthread_mutex_lock(&mu);
		while (_buffer == NULL) {
			pthread_cond_wait(&cond_c, &mu);
		}
		printf("Consumed buffer: %s\n", _buffer);
		_buffer = NULL;
		pthread_cond_signal(&cond_p);
		pthread_mutex_unlock(&mu);
	}
	pthread_exit(0);
}

int main() {
	pthread_t cons, prod;
	pthread_mutex_init(&mu, NULL);
	pthread_cond_init(&cond_c, NULL);
	pthread_cond_init(&cond_p, NULL);

	pthread_create(&prod, NULL, producer, NULL);
	pthread_create(&cons, NULL, consumer, NULL);

	pthread_join(cons, NULL);
	pthread_join(prod, NULL);

	pthread_mutex_destroy(&mu);
	pthread_cond_destroy(&cond_c);
	pthread_cond_destroy(&cond_p);

	return 0;
}
