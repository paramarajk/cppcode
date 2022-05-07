/*pthread conditional wait*/
#include <stdio.h>
#include <pthread.h>

#define MAX 3
int gval = 0;
pthread_mutex_t t_mutex;
pthread_cond_t cond1;

void* pth1_func(void* ptr) {
	printf("Entering into pth1_func\n");
	pthread_mutex_lock(&t_mutex);
	while (gval == 0) {
		printf("pthread_cond_wait called\n");
		printf("Gval from pth1_func is : %d\n", gval);
		pthread_cond_wait(&cond1, &t_mutex);
		printf("Completd pthread_cond_wait , gval is : %d\n", gval);
	}
	gval--;
	pthread_cond_signal(&cond1);
	pthread_mutex_unlock(&t_mutex);
	printf("Exiting into pth1_func\n");
}

void* pth2_func(void* ptr) {
	printf("Entering into pth2_func\n");
	pthread_mutex_lock(&t_mutex);
	while (gval == 0) {
		gval++;
	}
	printf("pthread_cond_signal called\n");
	printf("Gval from pth2_func is : %d\n", gval);
	pthread_cond_signal(&cond1);
	printf("Pthread cond signal completed, gval is : %d\n", gval);
	pthread_mutex_unlock(&t_mutex);
	printf("Exiting into pth2_func\n");
}

int main() {
	pthread_t th1, th2;
	pthread_mutex_init(&t_mutex, NULL);
	pthread_cond_init(&cond1, NULL);

	pthread_create(&th1, NULL, pth1_func, NULL);
	pthread_create(&th2, NULL, pth2_func, NULL);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	pthread_mutex_destroy(&t_mutex);

	return 0;
}

/*output:
pthread_cond_wait called
Gval from pth1_func is : 0
pthread_cond_signal called
Gval from pth2_func is : 1
Completd pthread_cond_wait , gval is : 1
*/
