#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h> // include this for wait()

int main(int argc, char const* argv[])
{
    pid_t id;
    printf("Before Fork\n");
    id = fork();

    if (id == 0)
    {
        printf("Child process: ID = %d PPID: %d\n", getpid(), getppid());
        wait(NULL); // Instead of sleep (10)
        printf("Child completed\n");
    }
    else if(id > 0)
    {
        printf("Parent process: ID = %d PPID: %d\n", getpid(), getppid());
        printf("Parent completed\n");
    }
    else
    {
        perror("Fork failed!\n");
    }
    
    return 0;

}