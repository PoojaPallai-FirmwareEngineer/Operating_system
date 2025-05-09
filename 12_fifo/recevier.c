#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const* argv[])
{
    unsigned char buff[5];
    int fd;

    // Create FIFO if it doesn't exist
    // Run in terminal before we execute mkfifo desdfifo
    mkfifo("desdfifo", 0666);

    fd = open("desdfifo", O_RDONLY);
    read(fd, buff, 5);
    printf("Read data: %s\n", buff);
    close(fd);

    return 0;
}