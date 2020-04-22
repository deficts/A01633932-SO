#include <stdio.h>
#include <pthread.h>

#define MAXTHREADS 5

int val = 5;
pthread_mutex_t mutex;

void * hello(void *id){
    pthread_mutex_lock(&mutex);
    printf("hello world %ld, valor: %d\n",(long)id,val);
    val+=val;
    pthread_mutex_unlock(&mutex);
};

int main(){
    pthread_t hilos[MAXTHREADS];
    for(long i =0;i < MAXTHREADS;i++){
        pthread_create(&hilos[i],NULL,hello,(void *)i);
    }
    pthread_exit(NULL);
    return 0;
}