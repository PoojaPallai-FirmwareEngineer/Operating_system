#include <stdio.h>      // For printf(), scanf(), perror()
#include <sys/types.h>  // For system data types
#include <unistd.h>     // For write(), close()
#include <stdlib.h>     // For exit(), EXIT_FAILURE, EXIT_SUCCESS
#include <sys/stat.h>   // For permission flags
#include <fcntl.h>      // For open() and file flags

int main(int argc, char const* argv[])
{
    int fd;
    int count = 0;

    scanf("%d", &count);  // Reading an integer input from user, though unused

    remove("Desdlog.txt");  // Delete existing file, if any

    // Open or create the file with write-only access and 0644 permission
    fd = open("Desdlog.txt", O_CREAT | O_WRONLY, 0664);

    if( -1 == fd)
    {
        perror("Error in opening file...\n");
        exit(EXIT_FAILURE);
    }

    printf("fd = %d\n", fd);
    write(fd, "DESD\n", 5);// Write 5 bytes to the file
    close(fd); 
    // exit(EXIT_FAILURE);

    return 0; // Indicate successful execution
}