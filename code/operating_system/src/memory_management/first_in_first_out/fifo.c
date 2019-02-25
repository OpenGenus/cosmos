/* Part of Cosmos by OpenGenus Foundation */

/*
 * Usage
 * -----
 * Compile : gcc -o fifo.o fifo.c
 * Run :
 *     1) either manually input the number of frames and the pages
 *     2) create a file consisting of the inputs to the executable in the
 *        processed order.
 *        then indirect the file into the executable command, like so :
 *        executable < input_file
 *
 *        SAMPLE INPUT FILE PROVIDED -> inputs.txt
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * For example-1, consider page reference string 1, 3, 0, 3, 5, 6 and 3 page
 * slots. Initially all slots are empty, so when 1, 3, 0 came they are allocated
 * to the empty slots —> 3 Page Faults. when 3 comes, it is already in  memory
 * so —> 0 Page Faults. Then 5 comes, it is not available in  memory so it
 * replaces the oldest page slot i.e 1. —>1 Page Fault. Finally 6 comes, it is
 * also not available in memory so it replaces the oldest page slot
 * i.e 3 —>1 Page Fault.
 */

/*
 * np > number of pages
 * nf > number of frames
 * p  > pages
 * fr > frames
 */
int fifo(int np, int nf, int *p, int *fr)
{
  int cnt = 0, flag, fault = 0, victim = -1;
  while (cnt != np) {
    flag = 0;
    for (int i = 0; i < nf; i++) {
      if (p[cnt] == fr[i]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      ++fault;
      ++victim;
      victim = victim % nf;
      fr[victim] = p[cnt];
    }
    ++cnt;
  }
  return fault;
}

/*
 * nf     > number of frames
 * frames > frames
 * fault  > number of faults
 */
void display(int nf, int *fr, int fault)
{
  printf("\nFrames after replacing : ");
  for (int i = 0; i < nf; i++) {
    printf("%d ", fr[i]);
  }
  printf("\nNo of faults = %d\n", fault);
}

int main()
{
  int n_frames, n_pages, fault;

  printf("Enter no of frames = ");
  scanf("%d", &n_frames);
  printf("Enter no of pages = ");
  scanf("%d", &n_pages);

  int *p = (int *)malloc(21 * sizeof(int));
  int *frames = (int *)malloc(n_frames * sizeof(int));

  printf("\nEnter page numbers\n");
  for (int i = 0; i < n_pages; i++) {
    printf("p[%d]=", i);
    scanf("%d", &p[i]);
    frames[i] = -1;
  }

  // get the number of faults using fifo page replacement
  fault = fifo(n_pages, n_frames, p, frames);
  display(n_frames, frames, fault);

  free(p);
  free(frames);
  return 0;
}
