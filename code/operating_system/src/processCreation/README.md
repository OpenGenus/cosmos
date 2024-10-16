# Create and handle Processes in Linux operating system.

## Understanding the fork, sleep, wait, exit, getpid, getppid system calls and ps, kill Linux commands.

fork() command is used to create a new process. 
getpid() and getppid() commands are used to display the PID(Process ID) of the child and parent processes.
wait() command is used to control the flow of execution.

### To see what programs are currently being executed on our system.

Use the **ps** command with some additional options that provide detailed information about the processes
running on our system.
-a lists processes of all users on the system
-u gives us details about the processes
-x lists processes that run unobtrusively in the background (these are known as daemons and usually end
with a d, like systemd).

### To narrow down the list of processes.

We can use **pgrep** to lookup the processes that match a specific pattern of text.
For example, pgrep -l chrome will search processes metadata for the pattern ‘chrome’, then
display the PIDs of those processes along with the program’s name.

[Click here for more and detailed information about Processes:](https://medium.com/@eightlimbed/creating-and-killing-processes-in-linux-7d4470f1f7a6)

