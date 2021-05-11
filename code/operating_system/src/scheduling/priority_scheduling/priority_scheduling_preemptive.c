// Priority scheduling: each process is assigned a priority. Process with
// highest priority is to be executed first and so on.

#include <stdio.h>
#include <stdlib.h>

typedef struct process 
{
  int pname, pr, at, bt;
  int ct, wt, rt, tat, flag; // flag=0 means unfinished process 
}process;

int next_process(process pro[], int n, int t);

int main() 
{
    int t = 0, n;
    process pro[20];
    float act=0, awt=0, atat=0, art=0;
    int ntemp, i;
    printf("Enter no. of process : ");
    scanf("%d", &n);
    for (i = 0; i < n; ++i) // input process details
    {
        printf("Enter Process Name : ");
        scanf("%d", &pro[i].pname);
        printf("Enter priority : ");
        scanf("%d", &pro[i].pr);
        printf("Enter arrival time : ");
        scanf("%d", &pro[i].at);
        printf("Enter burst time : ");
        scanf("%d", &pro[i].bt);
    }

    ntemp = n; // keeping value of n safe
    i = -1;
    printf("---------Gantt Chart--------\n\n");
    while (ntemp > 0) 
    {
        i = next_process(pro, n, t);
        if (i > -1) 
        {
            printf("%d| %d |%d \t", t, pro[i].pname, t + pro[i].bt);
            pro[i].rt = t;  // setting response time
            t += pro[i].bt; // updating time
            pro[i].ct = t;  // getting completion time
            pro[i].flag = 1; //flag=1 process is finished
            ntemp--;
        }

        else 
        {
            t++;
        }
    } // end of execution loop

    printf("\n\n----------Table--------\n\n");
    printf("Pname\tPriority\tAT\tBT\tCT\tWT\tTAT\tRT\n");
    for (i = 0; i < n; ++i) 
    {
        printf("%d\t%d\t\t%d\t%d\t", pro[i].pname, pro[i].pr, pro[i].at, pro[i].bt);
        pro[i].wt = pro[i].ct - pro[i].at - pro[i].bt;
        pro[i].tat = pro[i].ct - pro[i].at;
        printf("%d\t%d\t%d\t%d\n", pro[i].ct, pro[i].wt, pro[i].tat, pro[i].rt);
        act += pro[i].ct;
        awt += pro[i].wt;
        atat += pro[i].tat;
        art += pro[i].rt;
    }
    printf("---------Average Values----------\n\n");
    printf("Average CT = %.3f\n", act / n);
    printf("Average WT = %.3f\n", awt / n);
    printf("Average TAT = %.3f\n", atat / n);
    printf("Average RT = %.3f\n", art / n);

    return 0;
}

int next_process(process pro[], int n, int t) 
{
    int i, nprocess = -1;
    for (i = 0; i < n; ++i) 
    {
        if (pro[i].at <= t && pro[i].flag == 0)
        break;
    }

    if (i == n) 
    {
        return nprocess;
    }
    nprocess = i;

    for (; i < n; ++i) 
    {
        if (pro[i].at <= t && pro[i].flag == 0 && pro[i].pr < pro[nprocess].pr)
        nprocess = i;
    }
    return nprocess;
}