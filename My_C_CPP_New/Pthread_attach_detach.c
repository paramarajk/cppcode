#include <stdio.h>
#include <pthread.h>
#include <error.h>
#include <limits.h>
pthread_attr_t tha;

void* pth_func(void* arg) {
	char* msg = (char*)arg;
	printf("%s\n", msg);
	while (1) {
		printf("Thread1 id : %d\n", pthread_self());
	}
	return;
}

int main() {
	pthread_t th1;
	pthread_attr_init(&tha);
	int detach = PTHREAD_CREATE_DETACHED;
	pthread_attr_setdetachstate(&tha, detach);
	pthread_create(&th1, &tha, pth_func, "hello world");
	printf("Main thread id : %d\n", getpid());
	/*if(pthread_join(th1, NULL) != 0) {
		perror("ERROR : ");
	}*/
	pthread_attr_destroy(&tha);
	printf("Exiting from main\n");
	while (1) {};
	return 0;
}
