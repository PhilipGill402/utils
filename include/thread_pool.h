#ifndef INCLUDE_THREAD_POOL_C
#define INCLUDE_THREAD_POOL_C

#include <stdlib.h>
#include <pthread.h>
#include "queue.h"

typedef struct {
    void (*fn)(void*);
    void* arg;
}job_t;

typedef struct {
    pthread_t* workers;
    int num_workers;
    int active_workers;
    queue_t queue;
    pthread_mutex_t mutex;
    pthread_cond_t not_empty;
    pthread_cond_t not_full;
    pthread_cond_t finished;
    int accepting; //bool (1 or 0)
    int shutdown_requested; //bool (1 or 0)
    int graceful; //bool (1 or 0)

} thread_pool_t;

job_t init_job(void (*function)(void*), void* argument);

thread_pool_t* create_pool(int num_threads, int queue_capacity);
int submit_job(thread_pool_t* tp, void (*fn)(void*), void* arg);
void shutdown_pool(thread_pool_t* tp, int graceful);
void destroy_pool(thread_pool_t* pool);
void wait_pool(thread_pool_t* pool);

#endif 
