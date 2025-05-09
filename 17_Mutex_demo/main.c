#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t mutex_count; 

void *incthread(void* arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex_count);
        count++;
        printf("Inc thread:%d\n", count);
        pthread_mutex_unlock(&mutex_count);
    }
}

void *decthread(void* arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex_count);
        count--;
        printf("Dec thread:%d\n", count);
        pthread_mutex_unlock(&mutex_count);
    }
}

int main(int argc, char const* argv[])
{
    pthread_t inc, dec;

    pthread_mutex_init(&mutex_count, NULL);

    pthread_create(&inc, NULL, incthread, NULL);
    pthread_create(&dec, NULL, decthread, NULL);

    pthread_join(inc, NULL);
    pthread_join(dec, NULL);

    pthread_mutex_destroy(&mutex_count);

    return 0;
}