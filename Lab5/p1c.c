#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void sigchld_handler(int signum)
{
    int status;
    pid_t pid;

    while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
    {
        printf("Child process with PID %d has exited\n", pid);
    }
}

int main()
{
    signal(SIGCHLD, sigchld_handler);

    pid_t child_pid = fork();

    if (child_pid < 0)
    {
        perror("fork");
        exit(1);
    }
    else if (child_pid == 0)
    {
        // This is the child process

        // Fork another process (grandchild)
        pid_t grandchild_pid = fork();

        if (grandchild_pid < 0)
        {
            perror("fork");
            exit(1);
        }
        else if (grandchild_pid == 0)
        {
            // This is the grandchild process
            printf("Grandchild process with PID %d is exiting\n", getpid());
            exit(0);
        }
        else
        {
            // This is the child process
            sleep(2); // Sleep for 2 seconds to allow grandchild to terminate first
            printf("Child process with PID %d is exiting\n", getpid());
            exit(0);
        }
    }
    else
    {
        // Parent process
        while (1)
        {
            // Parent process continues execution
            sleep(1); // Sleep for a while to allow child processes to finish
        }
    }

    return 0;
}
