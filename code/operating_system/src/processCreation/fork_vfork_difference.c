/*fork() and vfork() are used for creating processes. They return values . If the value returned is zero , then it is child process otherwise it is parent process.

The basic difference between fork() and vfork() is 
In vfork() the parent and child share the same memory space as that of parent whereas in case of fork(), the child gets a copy of the parent and has a different memory space.
Therefore any value modified by the child id reflected in parent also in case of vfork() and the is not seen in fork();
In vfork(), it is the child that gets executed first everytime. The parent executes only after child has executed. 
In case of fork(), it cannot be said so. It depends on the scheduler as to who gets executed first(the child or the parent)

The below program depicts the differences
/*

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int vfork1=30,vfork2=40;
void forkFunction()
{	int pid,fork1=10,fork2=20;
	pid=fork();
	printf("\nfork1=%d,fork2=%d,This is executed by both parent and child(fork)\n",fork1,fork2);
	if(pid==0)	
	{	printf("This is executed by child (fork)\n");
		printf("\nfork1=%d\nfork2=%d\n",++fork1,++fork2);
	}
	else
	{	printf("\nThis is executed by parent (fork)\n");
		printf("fork1=%d\nfork2=%d\n",++fork1,++fork2);
	}
}

void vforkFunction()
{	int pid1;
	pid1=vfork();
	printf("\nvfork1=%d,vfork2=%d,This is executed by both parent and child(vfork)\n",vfork1,vfork2);
	if(pid1==0)
	{	printf("This is executed by child and is always executed first (vfork) no matter what\n");
		printf("\nvfork1=%d\nvfork2=%d\n",++vfork1,++vfork2);
	}
	else
	{	printf("\nThis is executed by parent and is always executed after child (vfork)\n");
		printf("vfork1=%d\nvfork2=%d\n",++vfork1,++vfork2);
		exit(0);
	}
}

int main()
{	printf("\nHere comes fork\n");	
	forkFunction();
	printf("\nHere comes vfork\n");
	vforkFunction();
	printf("this is not executed\n");
	return 0;
}

