/*
 * Part of Cosmos by OpenGenus Foundation.
 * Implementation of Hoare monitors using System V IPC.
 * An example of how to use monitors.
 * Author : ABDOUS Kamel
 */

#include "monitors.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#include <string.h>
#include <errno.h>

#define NB_CONDS 1

typedef struct
{
  int arrived;

} shm_mem;

int main()
{
  monitor mtor;
  create_monitor("p", 1, 2, NB_CONDS, sizeof(shm_mem), &mtor);

  if (!fork()) {
    printf("P1 starts.\n");

    /* init_monitor not necessary, just for the example. */
    init_monitor("p", 1, 2, &mtor);

    sleep(1);
    enter_monitor(&mtor);

    shm_mem* shm_ptr = mtor_shmat(&mtor);

    /* Don't wait if P2 arruved */
    if (!shm_ptr->arrived) {
      printf("P1 waits for P2.\n");
      mtor_wait(&mtor, 0);
    }

    printf("P1 continues, arrived = %d\n", shm_ptr->arrived);
    mtor_shmdt(shm_ptr);

    exit_monitor(&mtor);
    exit(0);
  }

  if (!fork()) {
    printf("P2 starts.\n");

    /* init_monitor not necessary, just for the example. */
    init_monitor("p", 1, 2, &mtor);

    sleep(3);
    enter_monitor(&mtor);

    shm_mem* shm_ptr = mtor_shmat(&mtor);
    shm_ptr->arrived = 1;
    mtor_shmdt(shm_ptr);

    printf("P2 wakes P1.\n");
    mtor_signal(&mtor, 0);

    exit_monitor(&mtor);
    exit(0);
  }

  while (wait(NULL) != -1) ;

  free_monitor(&mtor);
  return (0);
}
