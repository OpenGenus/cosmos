/*
 * Part of Cosmos by OpenGenus Foundation.
 * Implementation of Hoare monitors using System V IPC.
 * Author : ABDOUS Kamel
 */

#ifndef MONITORS_H
#define MONITORS_H

#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#include <sys/stat.h>
#include <fcntl.h>

/* Type of shared memory identificator */
typedef int SHM_ID;

/* Type of a semaphore identificator */
typedef int SEM_ID;

/* Number of monitor management semaphores */
#define EXTRA_SEMS_NB 2

/* Monitor mutual exclusion semaphore */
#define MTOR_MUTEX 0

/* Monitor signal semaphore */
#define MTOR_SIG_SEM 1

typedef struct
{
  SHM_ID sh_mem;
  SEM_ID sems_array;

} monitor;

/*
 * Create a brand new monitor, with [nb_conds] conditions and a shared memory
 * of size [shm_size].
 * [ftok_path] is used for generating a system V key for both shared memory and semaphores.
 * [shm_proj] is passed to ftok for shared memory, and [sem_proj] for semaphores.
 * @return 0 on success, -1 on failure.
 */
int 
create_monitor(char* ftok_path, int shm_proj, int sem_proj,
                   int nb_conds, size_t shm_size,  monitor* mtor);

/*
 * This function can be used to retrieve a monitor created by another process.
 * [ftok_path] is used for retrieving a system V key for both shared memory and semaphores.
 * [shm_proj] is passed to ftok for shared memory, and [sem_proj] for semaphores.
 * @return 0 on success, -1 on failure.
 */
int 
init_monitor(char* ftok_path, int shm_proj, int sem_proj, monitor* mtor);

/*
 * Free allocated semaphores and shared memory for the given monitor.
 * @return 0 on success, -1 on failure.
 */
int 
free_monitor(monitor* mtor);

/*
 * Ask to enter the monitor.
 * Only one process can be in the monitor.
 * @return 0 on success, -1 on failure.
 * Failure means that the demand failed, not that the process doesn't enter.
 */
int 
enter_monitor(monitor* mtor);

/*
 * Ask to leave the monitor.
 * Note that while leaving a monitor, pending processes on signal take precedence
 * over processes that asked to enter the monitor.
 * @return 0 on success, -1 on failure.
 * Failure means that the demand failed, not that the process doesn't enter.
 */
int 
exit_monitor(monitor* mtor);

/*
 * @return 1 if cond is empty (no process is waiting on it),
 * 0 if not empty, -1 on failure.
 */
int 
mtor_empty(monitor* mtor, int cond);

/*
 * Cause the process to wait for [cond].
 * Note that while leaving a monitor, pending processes on signal take precedence
 * over processes that asked to enter the monitor.
 * @return 0 on success, -1 on failure.
 */
int 
mtor_wait(monitor* mtor, int cond);

/*
 * If no process is waiting for [cond], do nothing.
 * If any, wake it and block on signal semaphore.
 * @return 0 on success, -1 on failure.
 */
int 
mtor_signal(monitor* mtor, int cond);

/*
 * Use this function to attach monitor shared memory.
 * @return Adress of the attached shared memory segment, NULL on failure.
 */
void* 
mtor_shmat(monitor* mtor);

/*
 * Use this function to detach monitor shared memory.
 * @return 0 on success, -1 on failure.
 */
int 
mtor_shmdt(void* shm_ptr);

#endif // MONITORS_H
