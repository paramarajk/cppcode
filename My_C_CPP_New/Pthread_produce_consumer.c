/*producer and consumenr problem*/
#include<stdio.h>
#include<pthread.h>

#define MAX 10
pthread_mutex_t t_mutex;
pthread_cond_t condc, condp;
const char* buffer = NULL;

void* producer(void* ptr) {
	int i;
	for (i = 1; i <= MAX; i++) {
		pthread_mutex_lock(&t_mutex);
		while (buffer != NULL) {
			pthread_cond_wait(&condp, &t_mutex);
		}
		buffer = "Hi";
		printf("Producer, produce the item : %s\n", buffer);
		pthread_cond_signal(&condc);
		pthread_mutex_unlock(&t_mutex);
	}
	pthread_exit(0);
}

void* consumer(void* ptr) {
	int i;
	for (i = 1; i <= MAX; i++) {
		pthread_mutex_lock(&t_mutex);
		while (buffer == NULL) {
			pthread_cond_wait(&condc, &t_mutex);
		}
		printf("Consumer, consume the item : %s\n", buffer);
		buffer = NULL;
		pthread_cond_signal(&condp);
		pthread_mutex_unlock(&t_mutex);
	}
	pthread_exit(0);
}

int main() {
	pthread_t cons, prod;
	pthread_mutex_init(&t_mutex, NULL);
	pthread_cond_init(&condc, NULL);
	pthread_cond_init(&condp, NULL);

	pthread_create(&cons, NULL, consumer, NULL);
	pthread_create(&prod, NULL, producer, NULL);

	pthread_join(cons, NULL);
	pthread_join(prod, NULL);

	pthread_cond_destroy(&condc);
	pthread_cond_destroy(&condp);
	pthread_mutex_destroy(&t_mutex);

	return 0;
}


/*output:
Producer, produce the item : 0
Consumer, consume the item : 1
Producer, produce the item : 0
Consumer, consume the item : 2
Producer, produce the item : 0
Consumer, consume the item : 3
Producer, produce the item : 0
Consumer, consume the item : 4
Producer, produce the item : 0
Consumer, consume the item : 5
Producer, produce the item : 0
Consumer, consume the item : 6
Producer, produce the item : 0
Consumer, consume the item : 7
Producer, produce the item : 0
Consumer, consume the item : 8
Producer, produce the item : 0
Consumer, consume the item : 9
Producer, produce the item : 0
Consumer, consume the item : 10
*/
