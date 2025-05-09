// Execution step -  gcc -o main main.c -lpthread
// ./main > out.txt

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int count = 0;
int limit = 20;

void *incthread(void* arg)
{
    while(count < limit)
    {
        printf("Inc thread:%d\n", count);
        count++;
        sleep(1); // slow down to see properly
    }
    pthread_exit(NULL); // exit after finish
}

void *decthread(void* arg)
{
    while(count > -limit)
    {
        printf("Dec thread:%d\n", count);
        count--;
        sleep(1); 
    }
    pthread_exit(NULL); // exit after finish
}

int main(int argc, char const* argv[])
{
    pthread_t inc, dec;

    pthread_create(&inc, NULL, incthread, NULL);
    pthread_create(&dec, NULL, decthread, NULL);

    pthread_join(inc, NULL);
    pthread_join(dec, NULL);

    return 0;
}
