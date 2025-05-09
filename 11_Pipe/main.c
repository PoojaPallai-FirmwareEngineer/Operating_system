#include <stdio.h>
#include <unistd.h> // for fork, pipe, read, write, close

#define MAX_BUFF_SIZE       5

int main(int argc, char const* argv[])
{
    unsigned char buff[MAX_BUFF_SIZE];
    pid_t id;
    int fd[2];

    pipe(fd);

    id = fork();
    
    if(id == 0)
    {
        close(fd[1]);
        printf("Child Process\n");
        read(fd[0], buff, sizeof(buff));
        printf("Child: Recieved data: %s\n", buff);
    }
    else
    {
        close(fd[0]);
        printf("Parent Process\n");
        write(fd[1], "DESD\n", 5);
        printf("Parent: Wrote data\n");
    }

    return 0;
}

