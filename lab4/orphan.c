#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Fork failed\n");
        return 1;
    }
    else if (pid > 0)
    {
    	// parent process
        printf("Parent: I am the parent process and my ID is %d\n", getpid());
        printf("Parent: I have created a child process whose id is %d\n", pid);
	    sleep(1);
	    exit(0);
    }

    else
    {
    	// child process
        printf("Child: I am a child process and my id is %d\n", getpid());
        printf("Child: I have been created by my parent process whose id is %d\n", getppid());
        sleep(30);
        printf("Child: I am a child process and my id is %d\n", getpid());
        printf("Child: My current parent id is %d\n", getppid());
        exit(1);
    }

    return 0;
}
