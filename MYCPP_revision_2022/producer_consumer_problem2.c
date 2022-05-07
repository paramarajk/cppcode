#include <stdio.h>
#include <pthread.h>

#define MAX 10
pthread_mutex_t mu;
pthread_cond_t condp, condc;
static int i = 0;
int buffer = 0;

void* producer(void *ptr) {
    for(; i <= MAX; i++) {
        pthread_mutex_lock(&mu);
        while(buffer != 0) {
            pthread_cond_wait(&condp, &mu);
        }
        buffer = 1;
        printf("producer: producing the value : %d\n", i);
        pthread_cond_signal(&condc);
        pthread_mutex_unlock(&mu);
    }
    pthread_exit(0);
}

void* consumer(void *ptr) {
    for(; i <= MAX; i++) {
        pthread_mutex_lock(&mu);
        while(buffer == 0) {
            pthread_cond_wait(&condc, &mu);
        }
        buffer = 0;
        printf("consumer: consuming the value : %d\n", i);
        pthread_cond_signal(&condp);
        pthread_mutex_unlock(&mu);
    }
    pthread_exit(0);
}


int main() {
    pthread_t cons, prod;
    
    //Intialize the mutex and cond
    pthread_mutex_init(&mu, NULL);
    pthread_cond_init(&condp, NULL);
    pthread_cond_init(&condc, NULL);
    
    //creting pthread
    pthread_create(&prod, NULL, consumer, NULL);
    pthread_create(&cons, NULL, producer, NULL);
    
    //Pthread join
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    
    //destroy the mutex and cond
    pthread_mutex_destroy(&mu);
    pthread_cond_destroy(&condp);
    pthread_cond_destroy(&condc);
    
    return 0;
}
