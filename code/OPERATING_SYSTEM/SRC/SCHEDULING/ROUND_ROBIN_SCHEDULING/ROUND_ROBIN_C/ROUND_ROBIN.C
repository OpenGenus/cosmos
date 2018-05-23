/*
 * Part of Cosmos by OpenGenus Foundation.
 * scanf is used for reading integers without any verification, so be careful.
 * Author : ABDOUS Kamel
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "queue.h"

typedef struct
{
  uint32_t turn_around, /* Total turn around of all processes */
           wait_time; /* Total wait time of all processes */

} perf_times;

typedef struct
{
  uint32_t id, /* Sequential id */
           arrival_time,
           burst_time,
           remain_time;

} process;

/*
 * Holds processes array and processes queue.
 */
typedef struct
{
  process* procs;
  uint32_t n;
  uint32_t next_arrive_proc; /* Index of next arriving process */

  queue p_queue;

} context_t;

/*
 * Init n processes with arrival time & burst time.
 */
int
init_procs(context_t* context);

/*
 * This function is used for sorting processes by ascendant arrival time.
 */
int
procs_sort_cmp(const void* proc1, const void* proc2);

/*
 * Free context_t struct.
 */
void
free_procs(context_t* context);

/*
 * Init performance structure by setting times to 0.
 */
void
init_perf_struct(perf_times* perf_struct);

/*
 * Check to see if new arriving processes must be enqueued.
 */
void
enqueue_arriving_processes(context_t* context, uint32_t cur_time);

int
main()
{
  uint32_t quantum;
  context_t context;

  /* Read quantum */
  printf("Enter quantum : ");
  scanf("%u", &quantum);

  /* Init context_t */
  if (init_procs(&context) == -1) {
    printf("Can't init procs, program will be closed.\n");
    return (1);
  }

  /* Start execution */
  perf_times perfs;
  init_perf_struct(&perfs);

  uint32_t nb_remain = context.n,
           cur_time = context.procs[0].arrival_time, /* cur_time is initialized to first arrival time */
           i = 0; /* Index of executing process */

  enqueue_arriving_processes(&context, cur_time);

  /* Run till all processes end */
  while (nb_remain != 0) {
    /* If the queue is empty, and there's still remaining processes,
       we move time forward to the next arriving process */
    if (queue_empty(&context.p_queue)) {
      cur_time = context.procs[context.next_arrive_proc].arrival_time;
      enqueue_arriving_processes(&context, cur_time);
    }

    i = dequeue(&context.p_queue);

    /* This is the end of the process */
    if (context.procs[i].remain_time <= quantum) {
      cur_time += context.procs[i].remain_time;
      context.procs[i].remain_time = 0;

      perfs.turn_around += (cur_time - context.procs[i].arrival_time);
      perfs.wait_time += (cur_time - context.procs[i].arrival_time - context.procs[i].burst_time);

      nb_remain--;

      printf("%d- Ended at %d.\n", context.procs[i].id, cur_time);
    }

    /* Execute till the end of the quantum */
    else {
      context.procs[i].remain_time -= quantum;
      cur_time += quantum;

      enqueue(&context.p_queue, i);

      printf("%d- Preempted at %d\n", context.procs[i].id, cur_time);
    }

    /* Maybe we have arriving processes */
    if (context.next_arrive_proc < context.n)
      enqueue_arriving_processes(&context, cur_time);
  }

  printf("\nAverage turn around : %d\n", perfs.turn_around / context.n);
  printf("Average wait time : %d\n", perfs.wait_time / context.n);

  free_procs(&context);
  return (0);
}

/*
 * Init n processes with arrival time & burst time.
 */
int
init_procs(context_t* context)
{
  printf("Enter total number of procs : ");
  scanf("%u", &context->n);

  context->procs = malloc(sizeof(process) * context->n);
  if (context->procs == NULL)
    return (-1);

  uint32_t i;
  for (i = 0; i < context->n; ++i) {
    /* Sequential id */
    context->procs[i].id = i + 1;

    printf("Arrival time of process %d : ", i + 1);
    scanf("%u", &context->procs[i].arrival_time);

    printf("Burst time of process %d : ", i + 1);
    scanf("%u", &context->procs[i].burst_time);

    context->procs[i].remain_time = context->procs[i].burst_time;
    printf("\n");
  }

  /* Sort processes by ascendant arrival time */
  qsort(context->procs, context->n, sizeof(process), procs_sort_cmp);

  /* Init processes queue */
  init_queue(&context->p_queue, context->n);

  context->next_arrive_proc = 0;

  return (0);
}

/*
 * This function is used for sorting processes by ascendant arrival time.
 */
int
procs_sort_cmp(const void* proc1, const void* proc2)
{
  const process* p1 = (process*)proc1;
  const process* p2 = (process*)proc2;

  return (p1->arrival_time - p2->arrival_time);
}

/*
 * Free context_t struct.
 */
void
free_procs(context_t* context)
{
  free(context->procs);
  free_queue(&context->p_queue);
}

/*
 * Init performance structure by setting times to 0.
 */
void
init_perf_struct(perf_times* perf_struct)
{
  perf_struct->turn_around = perf_struct->wait_time = 0;
}

/*
 * Check to see if new arriving processes must be enqueued.
 */
void
enqueue_arriving_processes(context_t* context, uint32_t cur_time)
{
  uint32_t i = context->next_arrive_proc;

  while (i < context->n && context->procs[i].arrival_time <= cur_time) {
    enqueue(&context->p_queue, i);
    ++i;
  }

  context->next_arrive_proc = i;
}
