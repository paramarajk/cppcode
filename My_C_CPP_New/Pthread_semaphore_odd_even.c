#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX 10
static int i = 1;
sem_t sm1, sm2;

void* func1(void* arg) {
	while (i <= MAX) {
		sem_wait(&sm1);
		printf("Thread1 : i is : %d\n", i++);
		sem_post(&sm2);
	}
}

void* func2(void* arg) {
	while (i <= MAX) {
		sem_wait(&sm2);
		printf("Thread2 : i is : %d\n", i++);
		sem_post(&sm1);
	}
}

int main(void) {
	pthread_t th1, th2;
	sem_init(&sm1, 0, 1);
	sem_init(&sm2, 0, 0);

	pthread_create(&th1, NULL, func1, NULL);
	pthread_create(&th2, NULL, func2, NULL);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	sem_destroy(&sm1);
	sem_destroy(&sm2);
	return 0;
}

/*output :
Thread1 : i is : 1
Thread2 : i is : 2
Thread1 : i is : 3
Thread2 : i is : 4
Thread1 : i is : 5
Thread2 : i is : 6
Thread1 : i is : 7
Thread2 : i is : 8
Thread1 : i is : 9
Thread2 : i is : 10
Thread1 : i is : 11

*/