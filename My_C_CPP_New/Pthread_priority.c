#include <stdio.h>
#include <pthread.h>
#include <sched.h>

pthread_attr_t tha;

void* pth_func1(void* arg) {
	int i = 0;
	for (; i < 10; i++) {
		printf("pth_fun1 Pthread id : %d\n", pthread_self());
	}
}

void* pth_func2(void* arg) {
	int i = 0;
	for (; i < 10; i++) {
		printf("pth_fun2 Pthread id : %d\n", pthread_self());
	}
}

int main() {
	pthread_attr_init(&tha);
	pthread_t th1, th2;
	struct sched_param param;

	if (pthread_attr_getschedparam(&tha, &param) != 0) {
		printf("Error in pthread_attr_getschedparam\n");
	}

	printf("%d\n", param.sched_priority);

	//param.sched_priority = sched_get_priority_max(SCHED_RR);
	param.sched_priority = 30;

	printf("%d\n", param.sched_priority);

	if (pthread_attr_setschedparam(&tha, &param) != 0) {
		printf("Error in pthread_attr_setschedparam\n");
	}

	pthread_create(&th1, NULL, pth_func1, NULL);
	pthread_create(&th2, &tha, pth_func2, NULL);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	return 0;
}
