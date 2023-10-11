#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    else if (pid > 0)
    { // parent process
        printf("Parent: My process ID is: %d\n", getpid());
        printf("Parent: The child process ID is: %d\n", pid);

        sleep(60); // Sleep for 1 minute
    }

    else
    { // child process
	printf("Child: My process ID is: %d\n", getpid());
        printf("Child: The parent process ID is: %d\n", getppid());

        printf("Child: Press Enter to exit...\n");
        getchar(); // Wait for user input

        printf("Child: Exiting...\n");
        exit(0);
    }

    return 0;
}
