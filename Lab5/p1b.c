#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void sigchld_handler(int signum) {
    int status;
    pid_t pid;

    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        printf("Child process with PID %d has exited\n", pid);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_child_processes>\n", argv[0]);
        return 1;
    }

    int num_child_processes = atoi(argv[1]);
    if (num_child_processes <= 0) {
        fprintf(stderr, "Please provide a positive integer as the number of child processes.\n");
        return 1;
    }

    signal(SIGCHLD, sigchld_handler);

    srand(time(NULL));

    for (int i = 0; i < num_child_processes; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            // This is the child process
            int sleep_duration = rand() % 5 + 1; // Sleep for a random duration between 1 and 5 seconds
            sleep(sleep_duration);
            printf("Child process with PID %d slept for %d seconds and is exiting\n", getpid(), sleep_duration);
            exit(0);
        }
    }

    // Parent process
    while (1) {
        // Parent process continues execution
        sleep(1); // Sleep for a while to allow child processes to finish
    }

    return 0;
}
