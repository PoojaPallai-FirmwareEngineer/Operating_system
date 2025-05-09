#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const* argv[])
{
    pid_t id;
    printf("Before Fork\n");
    id = fork();

    // It may be confusing for 1st time. So follow the if else method for better understanding.
    // printf("After fork\n"); 

    if (id == 0)
    {
        printf("After fork(child process)\n");
    }
    else if(id > 0)
    {
        printf("After fork (parent process)\n");
    }
    else
    {
        printf("Fork failed!\n");
    }
    return 0;
}