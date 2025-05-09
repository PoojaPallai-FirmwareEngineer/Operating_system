#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t mutex_count; 
pthread_mutexattr_t mutex_count_attr;

void *incthread(void* arg)
{
    while(1)
    {
        printf("Inc: Locked 1st time\n");
        pthread_mutex_lock(&mutex_count);

        printf("Inc: Locked 2nd time\n");
        pthread_mutex_lock(&mutex_count);

        printf("Inc: Changing count\n");

        count++;

        printf("Inc thread:%d\n", count);

        printf("Inc: Unlocked 1st time\n");
        pthread_mutex_unlock(&mutex_count);

        printf("Inc: Unlocked 2nd time\n");
        pthread_mutex_unlock(&mutex_count);
    }
}

void *decthread(void* arg)
{
    while(1)
    {
        printf("Dec:Locking\n");
        pthread_mutex_lock(&mutex_count);

        count--;
        printf("Dec thread:%d\n", count);

        printf("Dec: Unlocking\n");
        pthread_mutex_unlock(&mutex_count);
    }
}

int main(int argc, char const* argv[])
{
    pthread_t inc, dec;

    pthread_mutexattr_init(&mutex_count_attr);
    pthread_mutexattr_settype(&mutex_count_attr, PTHREAD_MUTEX_RECURSIVE);

    pthread_mutex_init(&mutex_count, &mutex_count_attr);

    pthread_create(&inc, NULL, incthread, NULL);
    pthread_create(&dec, NULL, decthread, NULL);

    pthread_join(inc, NULL);
    pthread_join(dec, NULL);

    pthread_mutex_destroy(&mutex_count);

    return 0;
}