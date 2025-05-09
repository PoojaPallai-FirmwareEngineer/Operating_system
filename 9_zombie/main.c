#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const* argv[])
{
    pid_t id;
    printf("Before Fork\n");
    id = fork();

    if (id == 0)
    {
        printf("Child process: ID = %d PPID: %d\n", getpid(), getppid());
        printf("Child completed\n");
    }
    else if(id > 0)
    {
        printf("Parent process: ID = %d PPID: %d\n", getpid(), getppid());
        sleep(10);
        printf("Parent completed\n");
    }
    else
    {
        perror("Fork failed!\n");
    }
    return 0;

}