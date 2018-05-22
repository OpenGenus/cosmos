// Part of Cosmos by OpenGenus Foundation.
// Banker's Algorithm: Safety Algorithm

#include <cstdio>

int main()
{
    // Initialize
    int available[10], allocation [10][10], maximum[10][10];
    int noOfProcesses, noOfResources, need[10][10];
    int work[10], finish[10] = {0}, i;

    //Inputs
    printf("Enter no. of processes ... ");
    scanf("%d", &noOfProcesses );

    printf("Enter no. of resources available ... ");
    scanf("%d", &noOfResources);
    printf("Enter instances ...\n");
    for (i = 0; i < noOfResources; i++)
    {
        printf("Resource %d: ", i + 1);
        scanf("%d", &available[i]);
        //Initializing Work
        work[i] = available[i];
    }
    printf("Enter allocation array ... \n");
    for (i = 0; i < noOfProcesses; i++)
        for (int j = 0; j < noOfResources; j++)
            scanf("%d", &allocation[i][j]);
    printf("Enter maximum array ... \n");
    for (i = 0; i < noOfProcesses; i++)
        for (int j = 0; j < noOfResources; j++)
            scanf("%d", &maximum[i][j]);
    printf("Need matrix is ... \n");
    for (i = 0; i < noOfProcesses; i++)
    {
        for (int j = 0; j < noOfResources; j++)
        {
            need[i][j] = maximum[i][j] - allocation[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }


    // Safety Algorithm
    int processesNotCompleted = noOfProcesses;
    int cp = 0, op[10];
    while (processesNotCompleted)
    {
        int aProcessCompleted = 0;
        for (int x = 0; x < noOfProcesses; x++)
            //Check if process is yet to finish
            if (!finish[x])
            {
                int possible = 1;
                for (int y = 0; y < noOfResources; y++)
                    if (need[x][y] > work[y])
                        possible = 0;
                // and if it's possible to complete a process
                if (possible)
                {

                    printf("Work after executing process %d : ", x);
                    for (int y = 0; y < noOfResources; y++)
                    {
                        work[y] += allocation[x][y];
                        printf("%d ", work[y]);
                    }
                    printf("\n");
                    finish[x] = 1;
                    op[cp++] = x;
                    processesNotCompleted--;
                    aProcessCompleted = 1;
                }
            }
        // if it's not possible to complete a proceess
        if (!aProcessCompleted)
            break;
    }

    // if all proccesses not completed
    if (processesNotCompleted)
        printf("Safe sequence not possible !");
    // else if all processes completed
    else
    {
        printf("Safe Sequence is : ");
        for (i = 0; i < cp; i++)
            printf("P%d ", op[i]);
    }

    return 0;
}
