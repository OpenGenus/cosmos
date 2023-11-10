#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#define SIZE 50
#define STD_INPUT 0
#define STD_OUTPUT 1
#define TRUE 1

void cd (char *pathname) { /*add cd fuction*/
    chdir(pathname);
}

int main(void)
{

    while (TRUE) {

        char *argv_1[SIZE]={0}, *argv_2[SIZE]={0}, *temp=NULL;
        char input[100]={0};
        int i, background=0, work;
        char *process_1, *process_2;
        int fd[2], _fd;        
        pid_t pid[2], _pid; /*_pid for the return value from fork()*/
        char *pathname;

        printf("C_Shell:");
        fgets(input, 100, stdin); /*stantard input stream*/

        if (input[strlen(input)-1]=='\n') { /*get the string length*/
            input[strlen(input)-1]='\0';
        }

        if (strchr(input, '&')!=NULL) { /*Search the first &*/
            char *p;
            p=strrchr(input, '&'); /*record the address of last & exist*/
            input[(int)(p-input)]='\0';
            background=1;
        }

        if (strstr(input,"cd")!=NULL) { /*cd function is a builtin*/
            temp = strtok(input, " ");
            for (i=0; i<=1; i++) {
                argv_1[i]=temp;
                temp=strtok(NULL, " ");
                cd(argv_1[1]);
            }
        }

        if (strchr(input, '|')!=NULL) { /*two-process*/
            work=1;
            process_1=strtok(input, "|");
            process_2=strtok(NULL, "|");

            temp=strtok(process_1, " ");
            for (i=0; i<SIZE && temp!=NULL ; i++) {
                argv_1[i]=temp;
                temp=strtok(NULL, " ");
            }

            temp=strtok(process_2, " ");
            for (i=0; i<SIZE && temp!=NULL ; i++) {
                argv_2[i]=temp;
                temp=strtok(NULL, " ");
            }
        }
        else if (strchr(input, '<')!=NULL) { /*input redirection，like read*/
            work=2;
            process_1=strtok(input, "<");
            process_2=strtok(NULL, "<");

            temp=strtok(process_1, " ");
            for (i=0; i<SIZE && temp!=NULL ; i++) {
                argv_1[i]=temp;
                temp=strtok(NULL, " ");
            }

            temp=strtok(process_2, " ");
            for (i=0; i<SIZE && temp!=NULL ; i++) {
                argv_2[i]=temp;
                temp=strtok(NULL, " ");
            }
        }
        else if (strchr(input, '>')!=NULL) { /*output redirection，like write*/
            work=3;
            process_1=strtok(input, ">");
            process_2=strtok(NULL, ">");

            temp=strtok(process_1, " "); 
            for (i=0; i<SIZE && temp!=NULL; i++) {
                argv_1[i]=temp;
                temp=strtok(NULL, " ");
            }

            temp=strtok(process_2, " ");
            for (i=0; i<SIZE && temp!=NULL; i++) {
                argv_2[i]=temp;
                temp=strtok(NULL, " ");
            }
        }
        else { /*one-process*/
            work=4;
            temp=strtok(input, " ");
            for (i=0; i<SIZE && temp!=NULL; i++) {
                argv_1[i]=temp;
                temp=strtok(NULL, " ");
            }
        }

        pipe(&fd[0]); /*create pipe and return two file descriptor*/
        /**/
        /*fd[0]put file descriptor for read，fd[1] put file descriptor for write*/

        if ((_pid=fork())!=0) { /*create child process*/
            if (background==1) {
                continue;
            }
            close(fd[0]); /*close pipe，if not it will cause dead lock*/
            close(fd[1]); /*close pipe*/
            waitpid(_pid, NULL, 0); /*wait child process exit。pid = -1 will wait any child process*/
        }
        else {
            switch (work) {
            case 1: /*two-process*/
                if ((pid[0]=fork())==0) {
                    close(fd[0]); /*close read*/
                    close(STD_OUTPUT); /*prepare new stdout*/
                    dup(fd[1]); 
                    close(fd[1]); 
                    execvp(argv_1[0], argv_1);
                    exit(0);
                }
                if ((pid[1]=fork())==0) {
                    close(fd[1]); /*close write*/
                    close(STD_INPUT); /*prepare new stdin*/
                    dup(fd[0]); 
                    close(fd[0]); 
                    execvp(argv_2[0], argv_2);
                    exit(0);
                }
                close(fd[0]); 
                close(fd[1]); 
                waitpid(pid[1], NULL, 0); /*pid[1]=0 will wait any wait group process ID and parent process that have same child process to leave*/
                break;

            case 2: /*input*/
                _fd=open(argv_2[0], O_RDONLY); 
                close(STD_INPUT);
                dup2(_fd, STD_INPUT); 
                close(_fd);
                execvp(argv_1[0], argv_1);
                break;

            case 3: /*output*/
                _fd=open(argv_2[0], O_WRONLY | O_CREAT | O_TRUNC, 0644); 
                close(STD_OUTPUT);
                dup2(_fd, STD_OUTPUT);
                close(_fd);
                execvp(argv_1[0], argv_1);
                break;

            case 4:
                execvp(argv_1[0], argv_1);
            }
        }
    }
    return (0);
}
