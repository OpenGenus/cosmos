#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

void *func(int n);
void sleep(unsigned msec);

pthread_t philosopher[5];
pthread_mutex_t chopstick[5];

int main()
{
    int i, k;
    void *msg;
    for (i = 1; i <= 5; ++i)
    {
        k = pthread_mutex_init(&chopstick[i], NULL);
        if (k == -1)
        {
            std::cout << "\nMutex initialization failed";
            exit(1);
        }
    }
    for (i = 1; i <= 5; ++i)
    {
        k = pthread_create(&philosopher[i], NULL, (void *)func, (int *)i);
        if (k != 0)
        {
            std::cout << "\nThread creation error \n";
            exit(1);
        }
    }
    for (i = 1; i <= 5; ++i)
    {
        k = pthread_join(philosopher[i], &msg);
        if (k != 0)
        {
            std::cout << "\nThread join failed \n";
            exit(1);
        }
    }
    for (i = 1; i <= 5; ++i)
    {
        k = pthread_mutex_destroy(&chopstick[i]);
        if (k != 0)
        {
            std::cout << "\nMutex Destroyed \n";
            exit(1);
        }
    }
    return 0;
}

void *func(int n)
{
    std::cout << "\nPhilosopher %d is thinking" << n;
    pthread_mutex_lock(&chopstick[n]);
    pthread_mutex_lock(&chopstick[(n + 1) % 5]);
    std::cout << "\nPhilosopher % d is eating " << n;
    sleep(3);
    pthread_mutex_unlock(&chopstick[n]);
    pthread_mutex_unlock(&chopstick[(n + 1) % 5]);
    std::cout << "\nPhilosopher %d Finished eating" << n;
    return;
}

void sleep(unsigned msec)
{
    struct timespec req, rem;
    int err;
    req.tv_sec = msec / 1000;
    req.tv_nsec = (msec % 1000) * 1000000;
    while ((req.tv_sec != 0) || (req.tv_nsec != 0))
    {
        if (nanosleep(&req, &rem) == 0)
            break;
        err = errno;
        if (err == EINTR)
        {
            req.tv_sec = rem.tv_sec;
            req.tv_nsec = rem.tv_nsec;
        }
        break;
    }
}