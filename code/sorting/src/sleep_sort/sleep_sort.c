/* Part of Cosmos by OpenGenus Foundation */

/* sleep sort works both in windows and linux*/

/* WINDOWS SPECIFIC CODE*/
#if defined(WIN32) || defined(_WIN32) || \
    defined(__WIN32) && !defined(__CYGWIN__)
#include <process.h>
#include <windows.h>

void
routine(void *a)
{
	int n = *(int *)a;
	Sleep(n);
	printf("%d ", n);
}

void
sleep_sort(int arr[], int n)
{
	HANDLE threads[n];

	int i;
	for (i = 0; i < n; ++i) {
		threads[i] = (HANDLE)_beginthread(&routine, 0, &arr[i]);
	}

	WaitForMultipleObjects(n, threads, TRUE, INFINITE);
}

/* LINUX SPECIFIC CODE*/
#elif defined(__linux__)
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void
fdpipe(FILE** read_fp, FILE** write_fp)
{
	int fds[2];

	int err = pipe(fds);
	assert(err == 0);

	*read_fp = fdopen(fds[0], "r");
	*write_fp = fdopen(fds[1], "w");
}

void
sleep_sort(int* values, size_t cnt)
{
	FILE *read_fp, *write_fp;

	fdpipe(&read_fp, &write_fp);

	size_t i;
	for (i = 0; i < cnt; ++i) {
		switch (fork()) {
			case -1:
				assert(0);
				break;
			case 0:
				/* child process */
				sleep(values[i]);
				fprintf(write_fp, "%d\n", values[i]);
				exit(0);
				break;
			default:
				break;
		}
	}
	fclose(write_fp);

	int tmp;
	for (i = 0; i < cnt; ++i) {
		tmp = fscanf(read_fp, "%d\n", values + i);
		assert(tmp == 1);
	}
}
#endif

int
main()
{
	int i;
	int arr[] = {2, 1, 4, 3};
	int n = sizeof(arr) / sizeof(arr[0]);

	sleep_sort(arr, n);

	/* print out the sorted elements*/
	for (i = 0; i < n; ++i) {
		printf("%d\n", arr[i]);
	}

	return (0);
}
