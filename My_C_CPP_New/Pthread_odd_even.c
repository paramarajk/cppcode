/*producer and consumenr problem*/
#include<stdio.h>
#include<pthread.h>

#define MAX 10
pthread_mutex_t t_mutex;
pthread_cond_t condc, condp;
int i = 1;

void* oddfunc(void* ptr) {
	while (i <= MAX) {
		pthread_mutex_lock(&t_mutex);
		while ((i % 2) == 0) {
			pthread_cond_wait(&condp, &t_mutex);
		}
		printf("Thread 1 : %d\n", i++);
		pthread_cond_signal(&condc);
		pthread_mutex_unlock(&t_mutex);
	}
	pthread_exit(0);
}

void* evenfunc(void* ptr) {
	while (i <= MAX) {
		pthread_mutex_lock(&t_mutex);
		while ((i % 2) != 0) {
			pthread_cond_wait(&condc, &t_mutex);
		}
		printf("Thread 2 : %d\n", i++);
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

	pthread_create(&cons, NULL, oddfunc, NULL);
	pthread_create(&prod, NULL, evenfunc, NULL);

	pthread_join(cons, NULL);
	pthread_join(prod, NULL);

	pthread_cond_destroy(&condc);
	pthread_cond_destroy(&condp);
	pthread_mutex_destroy(&t_mutex);

	return 0;
}


