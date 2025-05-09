#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const* argv[])
{
    int fd;
    fd = open("desdfifo", O_WRONLY);
    write(fd, "DESD\n", 5);
    close(fd);

    return 0;
}