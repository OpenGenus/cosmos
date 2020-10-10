/*
description: When a vfork system call is issued, the parent process will be suspended until 
	     the child process has either completed execution or been replaced with a new executable image
	     via one of the "exec" family of system calls. 
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#define print printf
int main(int argc, char const *argv[])
{
	printf("In parent process(A) before fork \n");
	printf("A : pid %d pgid %d ppid %d\n",getpid(),getpgid(0),getppid());
	int x;
	int a=5;
	int b =10;
	print("a is %d\n",a);
	print("b is %d\n",b);

	if((x=vfork())==0)
	{
		printf("In child process(B)\n");
		printf("B : pid %d pgid %d ppid %d\n",getpid(),getpgid(0),getppid());
		a=10;
		b=5;
		print("a is %d\n",a);
		print("b is %d\n",b);
		print("exiting child process\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		print("back in parent process\n");
		print("a is %d\n",a);//a is updated even in parent by child
		print("b is %d\n",b);//b is updated even in parent by child if vfork
	}
	return 0;
}
