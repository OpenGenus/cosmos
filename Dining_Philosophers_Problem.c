#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5  // Number of philosophers
#define LEFT (philosopher_num + N - 1) % N  // Left philosopher
#define RIGHT (philosopher_num + 1) % N     // Right philosopher

sem_t forks[N];      // Array of semaphores for forks (one for each fork)
sem_t mutex;         // Semaphore for controlling access to critical section

enum { THINKING, HUNGRY, EATING } state[N];  // Track the state of each philosopher
int philosophers[N] = {0, 1, 2, 3, 4};       // Array for philosopher IDs

// Function prototypes
void *philosopher(void *num);
void take_forks(int philosopher_num);
void put_forks(int philosopher_num);
void test(int philosopher_num);

int main() {
    pthread_t threads[N];  // Array of thread IDs
    int i;

    // Initialize semaphores
    sem_init(&mutex, 0, 1);  // Initialize mutex to 1 (binary semaphore)
    for (i = 0; i < N; i++) {
        sem_init(&forks[i], 0, 1);  // Initialize each fork semaphore to 1 (available)
    }

    // Create philosopher threads
    for (i = 0; i < N; i++) {
        pthread_create(&threads[i], NULL, philosopher, &philosophers[i]);
    }

    // Join philosopher threads
    for (i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy semaphores
    for (i = 0; i < N; i++) {
        sem_destroy(&forks[i]);
    }
    sem_destroy(&mutex);

    return 0;
}

// Function for philosopher's actions
void *philosopher(void *num) {
    int philosopher_num = *(int *)num;

    while (1) {
        // Philosopher is thinking
        printf("Philosopher %d is thinking\n", philosopher_num);
        sleep(1);

        // Philosopher becomes hungry and tries to take forks
        take_forks(philosopher_num);

        // Philosopher is eating
        sleep(2);  // Eating duration

        // Philosopher puts down forks after eating
        put_forks(philosopher_num);
    }
}

// Function to take forks (attempt to enter critical section)
void take_forks(int philosopher_num) {
    sem_wait(&mutex);  // Lock access to critical section

    state[philosopher_num] = HUNGRY;  // Philosopher is hungry
    printf("Philosopher %d is hungry\n", philosopher_num);

    test(philosopher_num);  // Try to acquire forks

    sem_post(&mutex);  // Unlock access to critical section
    sem_wait(&forks[philosopher_num]);  // Wait until forks are available
}

// Function to put down forks (exit critical section)
void put_forks(int philosopher_num) {
    sem_wait(&mutex);  // Lock access to critical section

    state[philosopher_num] = THINKING;  // Philosopher is thinking
    printf("Philosopher %d puts down forks and starts thinking\n", philosopher_num);

    // Test if neighbors can now eat
    test(LEFT);
    test(RIGHT);

    sem_post(&mutex);  // Unlock access to critical section
}

// Function to check if philosopher can eat
void test(int philosopher_num) {
    if (state[philosopher_num] == HUNGRY &&
        state[LEFT] != EATING &&
        state[RIGHT] != EATING) {

        state[philosopher_num] = EATING;  // Philosopher starts eating
        printf("Philosopher %d takes forks and starts eating\n", philosopher_num);

        sem_post(&forks[philosopher_num]);  // Signal that forks are taken
    }
}






// Semaphores are used to manage access to shared resources (forks).
// mutex ensures that only one philosopher can access the shared state array at a time.
// Each philosopher tries to pick up the fork to their left and right before eating.
// State Transitions:
// A philosopher can be either THINKING, HUNGRY, or EATING.
// The program checks if both the left and right philosophers are not eating before allowing a philosopher to eat.
// Deadlock Prevention: By making philosophers test the state of their neighbors before picking up forks, we avoid deadlock (where all philosophers are waiting forever).



