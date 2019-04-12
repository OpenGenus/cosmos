#include <pthread.h> 
#include <semaphore.h> 
#include <stdio.h>
#include<unistd.h>

#define N 6 
#define THINKING 2 
#define HUNGRY 1 
#define EATING 0 
#define LEFT (phnum + (N-1)) % N 
#define RIGHT (phnum + 1) % N 

int state[N]; 
int phil[N] = { 0, 1, 2, 3, 4, 5 }; 

sem_t mutex; 
sem_t S[N]; 

void test(int phnum){ 
   if (state[phnum] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING){ 
      // state that eating 
      state[phnum] = EATING;
      sleep(2); 
      printf("Phil %d using chopstick %d and %d\n", phnum + 1, LEFT + 1, phnum + 1); 
      printf("Phil %d is Eating\n", phnum + 1); 
      sem_post(&S[phnum]); 
   } 
} 

// take up chopsticks 
void take_fork(int phnum){ 
   sem_wait(&mutex); 

   state[phnum] = HUNGRY; 

   printf("Phil %d is Hungry\n", phnum + 1); 

   test(phnum); 
   sem_post(&mutex); 


   sem_wait(&S[phnum]); 

   sleep(1); 
} 

// put down chopsticks 
void put_fork(int phnum){ 
   sem_wait(&mutex); 

   state[phnum] = THINKING; 
   
   printf("Phil %d putting chopstick %d and %d down\n", 
      phnum + 1, LEFT + 1, phnum + 1); 
   printf("Phil %d is thinking\n", phnum + 1); 

   test(LEFT); 
   test(RIGHT); 
   sem_post(&mutex); 
} 

void* philospher(void* num){ 
   int* i = num; 
   sleep(1); 
   take_fork(*i); 
   sleep(0); 
   put_fork(*i);
   printf("\n");  
} 

int main(){ 
   int i; 
   pthread_t thread_id[N]; 

   // initialize the semaphores 
   sem_init(&mutex, 0, 1); 

   for (i = 0; i < N; i++) 
      sem_init(&S[i], 0, 0); 

   for (i = 0; i < N; i++) { 
      // create philosopher processes 
      pthread_create(&thread_id[i], NULL, philospher, &phil[i]); 
      printf("Phil %d is thinking\n", i + 1); 
   } 
   printf("\n");
   for (i = 0; i < N; i++) 
      pthread_join(thread_id[i], NULL);
   printf("No one left to eat\n");
   return 0; 
}