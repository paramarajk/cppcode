/* Pthread mutex*/
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mu;

int gval = 0;

void* pth1_func(void* num) {
	int* num1_ptr = (int*)num;
	int no = *num1_ptr;

	pthread_mutex_lock(&mu);
	printf("th1: Gval is : %d\n", gval);
	gval++;
	pthread_mutex_unlock(&mu);
	pthread_exit(0);
	//return;
}

void* pth2_func(void* num) {
	int* num1_ptr = (int*)num;
	int no = *num1_ptr;

	pthread_mutex_lock(&mu);
	printf("th2: Gval is : %d\n", gval);
	gval++;
	pthread_mutex_unlock(&mu);
	pthread_exit(0);
	//return;
}

int main() {
	int num1 = 10, num2 = 20;
	pthread_t th1, th2;

	int i;
	for (i = 0; i < 5; i++) {
		pthread_create(&th1, NULL, pth1_func, &num1);
		pthread_create(&th2, NULL, pth2_func, &num2);
	}
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	pthread_mutex_destroy(&mu);
	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/pthread=>./pth3
th1: Gval is : 0
th2: Gval is : 0
th1: Gval is : 1
th1: Gval is : 3
th2: Gval is : 2
th1: Gval is : 4
th2: Gval is : 5
th1: Gval is : 6
th1: Gval is : 8
th2: Gval is : 7
th2: Gval is : 10
th2: Gval is : 11
*/
