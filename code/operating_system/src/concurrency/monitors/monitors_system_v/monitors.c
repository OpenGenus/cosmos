/*
 * Part of Cosmos by OpenGenus Foundation.
 * Implementation of Hoare monitors using System V IPC.
 * Author : ABDOUS Kamel
 */

#include "monitors.h"

static struct sembuf mutex_up = {MTOR_MUTEX, 1, 0},
                     mutex_down = {MTOR_MUTEX, -1, 0},
                     sig_up = {MTOR_SIG_SEM, 1, 0},
                     sig_down = {MTOR_SIG_SEM, -1, 0},
                     cond_up = {0, 1, 0},
                     cond_down = {0, -1, 0};

union semun {
  int              val;    /* Value for SETVAL */
  struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
  unsigned short  *array;  /* Array for GETALL, SETALL */
  struct seminfo  *__buf;  /* Buffer for IPC_INFO
                             (Linux-specific) */
};


/*
 * Create a brand new monitor, with [nb_conds] conditions and a shared memory
 * of size [shm_size].
 * [ftok_path] is used for generating a system V key for both shared memory and semaphores.
 * [shm_proj] is passed to ftok for shared memory, and [sem_proj] for semaphores.
 * @return 0 on success, -1 on failure.
 */
int 
create_monitor(char* ftok_path, int shm_proj, int sem_proj,
                   int nb_conds, size_t shm_size,  monitor* mtor)
{
  key_t shm_key = ftok(ftok_path, shm_proj);
  if (shm_key == -1)
    return (-1);

  key_t sems_key = ftok(ftok_path, sem_proj);
  if (sems_key == -1)
    return (-1);

  mtor->sh_mem = shmget(shm_key, shm_size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
  if (mtor->sh_mem == -1)
    return (-1);

  /* First two semaphores are for internal usage, others are for conditions */
  mtor->sems_array = semget(sems_key, EXTRA_SEMS_NB + nb_conds, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
  if (mtor->sems_array == -1) {
    shmctl(mtor->sh_mem, IPC_RMID, NULL);
    return (-1);
  }

  /* Init mutex semaphore */
  union semun mutex_init;
  mutex_init.val = 1;

  if (semctl(mtor->sems_array, MTOR_MUTEX, SETVAL, mutex_init) == -1) {
    free_monitor(mtor);
    return (-1);
  }

  return (0);
}

/*
 * This function can be used to retrieve a monitor created by another process.
 * [ftok_path] is used for retrieving a system V key for both shared memory and semaphores.
 * [shm_proj] is passed to ftok for shared memory, and [sem_proj] for semaphores.
 * @return 0 on success, -1 on failure.
 */
int 
init_monitor(char* ftok_path, int shm_proj, int sem_proj, monitor* mtor)
{
  key_t shm_key = ftok(ftok_path, shm_proj);
  if (shm_key == -1)
    return (-1);

  key_t sems_key = ftok(ftok_path, sem_proj);
  if (sems_key == -1)
    return (-1);

  mtor->sh_mem = shmget(shm_key, 0, S_IRUSR | S_IWUSR);
  if (mtor->sh_mem == -1)
    return (-1);

  mtor->sems_array = semget(sems_key, 0, S_IRUSR | S_IWUSR);
  if (mtor->sems_array == -1)
    return (-1);
}

/*
 * Free allocated semaphores and shared memory for the given monitor.
 * @return 0 on success, -1 on failure.
 */
int 
free_monitor(monitor* mtor)
{
  int ret = shmctl(mtor->sh_mem, IPC_RMID, NULL);
  ret = semctl(mtor->sems_array, 0, IPC_RMID);

  return (ret);
}

/*
 * Ask to enter the monitor.
 * Only one process can be in the monitor.
 * @return 0 on success, -1 on failure.
 * Failure means that the demand failed, not that the process doesn't enter.
 */
int 
enter_monitor(monitor* mtor)
{
  return (semop(mtor->sems_array, &mutex_down, 1));
}

/*
 * Ask to leave the monitor.
 * Note that while leaving a monitor, pending processes on signal take precedence
 * over processes that asked to enter the monitor.
 * @return 0 on success, -1 on failure.
 * Failure means that the demand failed, not that the process doesn't enter.
 */
int 
exit_monitor(monitor* mtor)
{
  int nb_sig_wait = semctl(mtor->sems_array, MTOR_SIG_SEM, GETNCNT);

  /* semctl error */
  if (nb_sig_wait == -1)
    return (-1);

  /* Wake a pending process on signal */
  else if (nb_sig_wait > 0) {
    if (semop(mtor->sems_array, &sig_up, 1) == -1)
      return (-1);

    else
      return (0);
  }

  /* Wake a pending process on monitor entrance */
  else
    return (semop(mtor->sems_array, &mutex_up, 1));
}

/*
 * @return 1 if cond is empty (no process is waiting on it),
 * 0 if not empty, -1 on failure.
 */
int 
mtor_empty(monitor* mtor, int cond)
{
  return (semctl(mtor->sems_array, EXTRA_SEMS_NB + cond, GETNCNT));
}

/*
 * Cause the process to wait for [cond].
 * Note that while leaving a monitor, pending processes on signal take precedence
 * over processes that asked to enter the monitor.
 * @return 0 on success, -1 on failure.
 */
int 
mtor_wait(monitor* mtor, int cond)
{
  if (exit_monitor(mtor) == -1)
    return (-1);

  /* Do wait */
  cond_down.sem_num = EXTRA_SEMS_NB + cond;
  return (semop(mtor->sems_array, &cond_down, 1));
}

/*
 * If no process is waiting for [cond], do nothing.
 * If any, wake it and block on signal semaphore.
 * @return 0 on success, -1 on failure.
 */
int 
mtor_signal(monitor* mtor, int cond)
{
  int cond_empty = mtor_empty(mtor, cond);

  /* Wake a pending process on cond */
  if (cond_empty > 0) {
    cond_up.sem_num = EXTRA_SEMS_NB + cond;
    if (semop(mtor->sems_array, &cond_up, 1) == -1)
      return (-1);

    /* Wait on signal */
    return (semop(mtor->sems_array, &sig_down, 1));
  }

  return (cond_empty);
}

/*
 * Use this function to attach monitor shared memory.
 * @return Adress of the attached shared memory segment, NULL on failure.
 */
void* 
mtor_shmat(monitor* mtor)
{
  return (shmat(mtor->sh_mem, NULL, 0));
}

/*
 * Use this function to detach monitor shared memory.
 * @return 0 on success, -1 on failure.
 */
int 
mtor_shmdt(void* shm_ptr)
{
  return (shmdt(shm_ptr));
}
