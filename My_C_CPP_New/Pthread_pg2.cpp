#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int gval = 0;

void* display_func(void* arg) {
	printf("display_func : Gval is : %d\n", gval);
	gval++;
	pthread_exit(0);
}

void* display_func1(void* arg) {
	printf("display_func1 : Gval is : %d\n", gval);
	gval++;
	pthread_exit(0);
}

int main() {
	pthread_t th1, th2;

	int i;
	for (i = 0; i < 10; i++) {
		pthread_create(&th1, NULL, display_func, NULL);
		pthread_create(&th2, NULL, display_func1, NULL);
	}


	pthread_join(th1, NULL);
	return 0;
}

/*
paramibm@:/gsa/ausgsa/projects/i/islaixgsa/paramibm/test/my_Learning/Revision_CPP/my_own_concept/pthread=>./pth2
display_func : Gval is : 0
display_func1 : Gval is : 0
display_func : Gval is : 1
display_func1 : Gval is : 2
display_func : Gval is : 4
display_func1 : Gval is : 5
display_func : Gval is : 5
display_func1 : Gval is : 7
display_func : Gval is : 8
display_func1 : Gval is : 9
display_func : Gval is : 10
display_func1 : Gval is : 11
display_func : Gval is : 12
display_func1 : Gval is : 13
display_func : Gval is : 14
display_func1 : Gval is : 15
display_func : Gval is : 16
display_func1 : Gval is : 17
display_func : Gval is : 18
display_func1 : Gval is : 19
*/
