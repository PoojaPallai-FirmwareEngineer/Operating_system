#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t mutex_count; 

void *incthread(void* arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex_count);
        printf("Inc is sleeping\n");
        sleep(1);
        count++;
        printf("Inc thread:%d\n", count);
        pthread_mutex_unlock(&mutex_count);
    }
}

void *decthread(void* arg)
{
    int res = 0;
    while(1)
    {
        res = pthread_mutex_trylock(&mutex_count);

        // You should check res from pthread_mutex_trylock first:
        // If res == 0, then you have acquired the lock → safe to work
        // If res != 0, then you did not acquire lock → skip decrement and unlock
        
        if (res == 0)
        {
            printf("Dec is sleeping\n");
            sleep(1);
            count--;
            printf("Dec thread:%d\n", count);
            pthread_mutex_unlock(&mutex_count);
        }
        else
        {
            printf("Dec thread: lock busy, skipping\n");
            sleep(1); // Optional sleep to avoid busy-waiting
        }
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