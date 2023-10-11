#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int exit_requested = 0;

void sigint_handler(int signum)
{
    printf("\nReceived SIGINT. Do you really want to exit? (y/n) ");
    char response;
    scanf(" %c", &response);
    if (response == 'y' || response == 'Y')
    {
        exit_requested = 1;
    }
    else
    {
        printf("Continuing...\n");
    }
}

void sigterm_handler(int signum)
{
    printf("\nReceived SIGTERM. Do you really want to exit? (y/n) ");
    char response;
    scanf(" %c", &response);
    if (response == 'y' || response == 'Y')
    {
        exit_requested = 1;
    }
    else
    {
        printf("Continuing...\n");
    }
}

int main()
{
    signal(SIGINT, sigint_handler);
    signal(SIGTERM, sigterm_handler);

    int count_to = 10; // Change this to specify the count limit

    while (!exit_requested)
    {
        for (int i = 1; i <= count_to; i++)
        {
            printf("%d ", i);
            fflush(stdout);
            sleep(1); // Add a delay of 1 second between numbers
        }
        printf("\n");
    }

    printf("Exiting...\n");

    return 0;
}
