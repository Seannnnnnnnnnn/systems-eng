#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv [])
{
    sched_setaffinity(1);
    printf("hello world from main process (%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0)  // system call failed
        printf("uh oh");
    else if (rc == 0)
        printf("hello world from child process (%d)\n", (int) getpid());
    else
        printf("hello world from parent process (%d)\n", (int) getpid());
    
    return 0;
}