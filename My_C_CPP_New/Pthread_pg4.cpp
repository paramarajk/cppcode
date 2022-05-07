/*semaphore concept*/
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

int gval = 100;
sem_t sem;

void* pth1_func(void* num) {
	int no = (int)num;
	int val;
	while (no != 0) {
		val = sem_wait(&sem);
		if (val != 0) {
			printf("pth1_func: sem_wait failed with error : \n");
		}
		else {
			printf("pth1_func: The thread_number is : %d\n", no);
		}
		no--;
	}

	pthread_exit(0);
}


void* pth2_func(void* num) {
	int no = (int)num;
	int val;
	while (no != 0) {
		val = sem_wait(&sem);
		if (val != 0) {
			printf("pth2_func: sem_wait failed with error : \n");
		}
		else {
			printf("pth2_func: The thread_number is : %d\n", no);
		}
		no--;
	}

	pthread_exit(0);
}

int main() {
	printf("!!!pthread!!!\n");
	int status = 0;
	int num1 = 5, num2 = 5, num3 = 10;
	pthread_t th1, th2;

	status = sem_init(&sem, 0, 0);
	if (status != 0) {
		printf("The semaphore init failed with error: \n");
		return -1;
	}

	status = pthread_create(&th1, NULL, pth1_func, (void*)num1);
	if (status != 0) {
		printf("Ptherad1 creation failed\n");
		return -1;
	}

	status = pthread_create(&th2, NULL, pth2_func, (void*)num2);
	if (status != 0) {
		printf("Ptherad2 creation failed\n");
		return -1;
	}

	while (num3 != 0) {
		printf("The posting semaphore from main_thread_no is : %d\n", (int)pthread_self());
		status = sem_post(&sem);
		if (status != 0) {
			printf("sem_post failed with error : \n");
		}
		usleep(2000000);
		num3--;
	}
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/pthread=>./pth4
!!!pthread!!!
The posting semaphore from main_thread_no is : 1
pth1_func: The thread_number is : 5
The posting semaphore from main_thread_no is : 1
pth2_func: The thread_number is : 5
The posting semaphore from main_thread_no is : 1
pth1_func: The thread_number is : 4
The posting semaphore from main_thread_no is : 1
pth2_func: The thread_number is : 4
The posting semaphore from main_thread_no is : 1
pth1_func: The thread_number is : 3
The posting semaphore from main_thread_no is : 1
pth2_func: The thread_number is : 3
The posting semaphore from main_thread_no is : 1
pth1_func: The thread_number is : 2
The posting semaphore from main_thread_no is : 1
pth2_func: The thread_number is : 2
The posting semaphore from main_thread_no is : 1
pth1_func: The thread_number is : 1
The posting semaphore from main_thread_no is : 1
pth2_func: The thread_number is : 1
*/
