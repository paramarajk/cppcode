#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX 10

sem_t sem, sem1, sem2;
int val = 0;

void* thread_func(void* arg) {
	if (sem_wait(&sem) < 0) {
		printf("Sem_wait failed\n");
	}
	printf("sem : The val is : %d\n", ++val);
	sleep(20);
	if (sem_post(&sem) < 0) {
		printf("Sem_post failed\n");
	}
}

void* thread_func1(void* arg) {
	if (sem_wait(&sem) < 0) {
		printf("Sem_wait failed\n");
	}
	printf("sem1 : The val is : %d\n", ++val);
	sleep(100);
	if (sem_post(&sem) < 0) {
		printf("Sem_post failed\n");
	}
}



int main() {
	pthread_t th1, th2;
	sem_init(&sem, 0, 2);

	int i = 0;
	
	pthread_create(&th1, NULL, thread_func, NULL);
	pthread_create(&th2, NULL, thread_func1, NULL);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	sem_destroy(&sem);
	return 0;
}
