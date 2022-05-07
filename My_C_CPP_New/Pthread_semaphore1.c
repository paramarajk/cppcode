#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX 10

sem_t sem/*, sem1*/;
int val = 0;

void* thread_func(void* arg) {
	while (val < MAX) {
		if (sem_wait(&sem) < 0) {
			printf("Sem_wait failed\n");
		}
		printf("T1: The val is : %d\n", ++val);

		if (sem_post(&sem) < 0) {
			printf("Sem_post failed\n");
		}
	}
}
/*void *thread_func1(void *arg) {
	while(val < MAX) {
		if(sem_wait(&sem1) < 0) {
			printf("Sem_wait failed\n");
		}
		printf("T2: The val is : %d\n", ++val);

		if(sem_post(&sem) < 0) {
			printf("Sem_post failed\n");
		}
	}
}*/

int main() {
	pthread_t th1, th2;
	if (sem_init(&sem, 0, 1) < 0) {
		printf("Sem initialization failed\n");
	}
	else {
		printf("Sem initialization passed\n");
	}

	/*if(sem_init(&sem1, 0, 0) < 0) {
		printf("Sem1 initialization failed\n");
	} else {
		printf("Sem1 initialization passed\n");
	}*/

	pthread_create(&th1, NULL, thread_func, NULL);
	pthread_create(&th2, NULL, thread_func, NULL);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	sem_destroy(&sem);
	/*sem_destroy(&sem1);*/
	return 0;
}
