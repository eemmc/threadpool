#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "pthreadpool.h"


void* handle1(void* ptr) {
    unsigned int i;
    for(i = 0; i < 64; i++){
        fprintf(stdout, "thread1: %ld => %u\n", pthread_self(), i);
    }
    return NULL;
}

void* handle2(void* ptr) {
    unsigned int i;
    for(i = 0; i < 64; i++){
        fprintf(stdout, "thread2: %ld => %u\n", pthread_self(), i);
    }
    return NULL;
}

int main() {

    pthread_pool_t pool;
    pthread_pool_setup(&pool, 3);

    pthread_pool_spawn(&pool, handle1, NULL);
    pthread_pool_spawn(&pool, handle2, NULL);
    pthread_pool_spawn(&pool, handle2, NULL);
    pthread_pool_spawn(&pool, handle1, NULL);
    pthread_pool_spawn(&pool, handle2, NULL);
    pthread_pool_spawn(&pool, handle1, NULL);


    sleep(2);
    pthread_pool_release(&pool);


    return 0;
}
