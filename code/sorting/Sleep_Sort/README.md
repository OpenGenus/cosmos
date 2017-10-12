# Sleep Sort

The **sleep sort** algorithm is closely related to the operating system. Each input is placed in a new thread which will sleep for a certain amount of time that is proportional to the value of its element. For example, a thread with a value of 10 will sleep longer than a thread with a value of 2. The thread with the least amount of sleep time gets printed first. When the next thread is done sleeping, that element is then printed. The output is thus sorted.

## Limitations
* Won’t work with negative values since the OS can’t sleep for a negative amount of time
* Huge amounts of elements will cause the algorithm to be slow
* Elements with large values will cause a slow algorithm.
