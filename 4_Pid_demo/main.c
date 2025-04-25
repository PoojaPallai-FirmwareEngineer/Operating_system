#include <stdio.h>      // Provides input/output functions like printf()
#include <sys/types.h>  // Defines system data types like pid_t
#include <unistd.h>     // Declares system calls like getpid() and getppid()

int main(int argc, char const* argv[])
{
    pid_t pid;     // Variable to store process ID
    pid_t ppid;    // Variable to store parent process ID

    pid = getpid(); // Get the current process ID
    printf("Process ID Pid: %d\n", pid);

    ppid = getppid(); // Get the parent process ID
    printf("Parent Process ID PPid: %d\n", ppid);

    return 0;

}