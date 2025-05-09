// Execution step - gcc -o main main.c -lpthread

#include <stdio.h>
#include <pthread.h>
#include <sys/wait.h> // include this for wait()

pthread_t id;

void *display(void *data)
{
    printf("This is a thread\n");
} 

int main(int argc, char const* argv[])
{

    printf("Before Thread Creation\n");
    pthread_create(&id, NULL, display, NULL);
    wait(NULL);
    printf("After thread creation\n");
    return 0;
}

