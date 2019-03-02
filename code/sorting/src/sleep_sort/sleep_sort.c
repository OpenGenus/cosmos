/* Part of Cosmos by OpenGenus Foundation */

/* sleep sort works both in windows and linux*/

/* WINDOWS SPECIFIC CODE*/
#if defined(WIN32) || defined(_WIN32) || \
    defined(__WIN32) && !defined(__CYGWIN__)
#include <process.h>
#include <windows.h>
void routine(void *a)
{
  int n = *(int *)a;
  Sleep(n);
  printf("%d ", n);
}

void sleepSort(int arr[], int n)
{
  int i;
  HANDLE threads[n];
  for (i = 0; i < n; i++)
    threads[i] = (HANDLE)_beginthread(&routine, 0, &arr[i]);
  WaitForMultipleObjects(n, threads, TRUE, INFINITE);
  return;
}

/* LINUX SPECIFIC CODE*/
#elif defined(__linux__)
#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void fdpipe(FILE** readFp, FILE** writeFp)
{
  int fds[2], err;

  err = pipe(fds);
  assert(err == 0);

  *readFp = fdopen(fds[0], "r");
  *writeFp = fdopen(fds[1], "w");
}

void sleepSort(int* values, size_t cnt)
{
  FILE *readFp, *writeFp;
  size_t i;
  int tmp;

  fdpipe(&readFp, &writeFp);

  for (i = 0; i < cnt; i++) switch (fork()) {
      case -1:
        assert(0);
        break;
      case 0:
        /* child process */
        sleep(values[i]);
        fprintf(writeFp, "%d\n", values[i]);
        exit(0);
        break;
      default:
        break;
    }
  fclose(writeFp);

  for (i = 0; i < cnt; i++) {
    tmp = fscanf(readFp, "%d\n", values + i);
    assert(tmp == 1);
  }
}
#endif

int main()
{
  int i;
  int arr[] = {2, 1, 4, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  sleepSort(arr, n);

  /* print our the sorted elements*/
  for (i = 0; i < n; i++) printf("%d\n", arr[i]);

  return 0;
}
