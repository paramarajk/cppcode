/* Thread program*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

long long sum = 0;

void* sum_runner(void* arg) {
	long long* limit_ptr = (long long*)arg;
	long long limit = *limit_ptr;

	printf("This is sum_runner\n");
	long long i;
	for (i = 0; i < limit; ++i) {
		sum += i;
	}

	pthread_exit(0);

}

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("Enter the 2 argument\n");
		exit(-1);
	}

	long long limit = atoll(argv[1]);

	pthread_t th1;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	pthread_create(&th1, &attr, sum_runner, &limit);
	pthread_join(th1, NULL);

	printf("The sum is :%lld\n", sum);

	return 0;
}
/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/pthread=>./pth1 5
The argc value is : 2
This is sum_runner
The sum is :10
*/
