// sleep sort for ubuntu as the earlier code was using windows.h header and due to which travis was not able to build any project.
// trying to solve the problem of build --- dated 21 may 2018--10:26 IST
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

void sleep_sort(int* values, size_t cnt)
{
  FILE* readFp, * writeFp;
  size_t i;
  int tmp;

  fdpipe(&readFp, &writeFp);
  
  for (i = 0; i < cnt; i++)
    switch (fork()) {
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

int main(int argc, char** argv)
{
  int values[] = { 1, 9, 5, 3 };
  int i;

  signal(SIGCHLD, SIG_IGN);

  sleep_sort(values, 4);

  for (i = 0; i < 4; i++)
    printf("%d\n", values[i]);

  return 0;
}
