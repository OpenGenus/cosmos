// Peterson's algorithm
// C implementation
// Here mythreads.h is a file externally included by me with some assertion statements
#include <stdio.h>
#include <pthread.h>
#include"mythreads.h"

int flag[2];
int turn;
const int MAX = 1e9;
int ans = 0;

void lock_init()
{
    // Initialize lock by reseting the desire of
    // both the threads to acquire the locks.
    // And, giving turn to one of them.
    flag[0] = flag[1] = 0;
    turn = 0;
}

// Executed before entering critical section
void lock(int self)
{
    // Set flag[self] = 1 saying you want to acquire lock
    flag[self] = 1;

    // But, first give the other thread the chance to
    // acquire lock
    turn = 1-self;

    // Wait until the other thread looses the desire
    // to acquire lock or it is your turn to get the lock.
    while (flag[1-self]==1 && turn==1-self) ;
}

// Executed after leaving critical section
void unlock(int self)
{
    // You do not desire to acquire lock in future.
    // This will allow the other thread to acquire
    // the lock.
    flag[self] = 0;
}

// A Sample function run by two threads created
// in main()
void* func(void *s)
{
    int i = 0;
    int self = (int *)s;
    printf("Thread Entered: %d\n", self);

    lock(self);

    // Critical section (Only one thread
    // can enter here at a time)
    for (i=0; i<MAX; i++)
        ans++;

    unlock(self);
}

// Driver code
int main()
{
    // Initialized the lock then fork 2 threads
    pthread_t p1, p2;
    lock_init();

    // Create two threads (both run func)
    pthread_create(&p1, NULL, func, (void*)0);
    pthread_create(&p2, NULL, func, (void*)1);

    // Wait for the threads to end.
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("Actual Count: %d | Expected Count: %d\n",
                                        ans, MAX*2);

    return 0;
}
