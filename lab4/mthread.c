#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 2

pthread_mutex_t mutex;
long long result = 0;

void *add(void *arg)
{
    long long *args = (long long *)arg;
    long long start = args[0];
    long long end = args[1];

    long long local_sum = 0;
    for (long long i = start; i <= end; ++i)
    {
        local_sum += i;
    }

    pthread_mutex_lock(&mutex);
    result += local_sum;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <N>\n", argv[0]);
        return 1;
    }

    long long n = atoll(argv[1]);
    if (n <= 0)
    {
        fprintf(stderr, "N must be a positive integer\n");
        return 1;
    }

    pthread_t t1, t2;
    long long thread_args[MAX_THREADS][2];

    pthread_mutex_init(&mutex, NULL);

    thread_args[0][0] = 1;
    thread_args[0][1] = n / 2;
    thread_args[1][0] = n / 2 + 1;
    thread_args[1][1] = n;

    pthread_create(&t1, NULL, add, thread_args[0]);
    pthread_create(&t2, NULL, add, thread_args[1]);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);

    printf("Sum of the first %lld natural numbers: %lld\n", n, result);

    return 0;
}
