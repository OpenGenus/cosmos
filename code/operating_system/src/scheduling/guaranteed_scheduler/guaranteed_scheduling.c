/*
Guaranteed scheduler is a specialized scheduling algorithm designed to ensure that specific processes receive a guaranteed share of CPU time. This scheduler represents a basic implementation of a Guaranteed Scheduling Scheduler with Priority Levels. It demonstrates a simple but effective approach to priority-based scheduling and provides a clear log for tracking job execution.

Philosophy behind Guaranteed Scheduler: Priority-Based Scheduling, Dynamic Time Quantum, Logging and Transparency, Random Priority Assignment
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_JOBS 15
#define NUM_PRIORITIES 3 /* Example: 3 priority levels */ 
#define TIME_QUANTUM_HIGH 10
#define TIME_QUANTUM_MEDIUM 5
#define TIME_QUANTUM_LOW 2

struct Job
{
    int id;
    int cpu_burst;
    int io_burst;
    int remaining_cpu_burst;
    int priority; /* Priority level */ 
};

/* Function to log output to console and a file */ 
void 
logToFileAndConsole(const char *message, const char *filename)
{
    FILE *file = fopen(filename, "a"); /* Open file in append mode */ 
    if (!file)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    /* Log to both the console and the file */ 
    printf("%s", message);
    fprintf(file, "%s", message);

    fclose(file);
}

void 
guaranteedScheduling(struct Job *jobRequests, int maxJobs)
{
    int currentTime = 0;
    int completedJobs = 0;

    /* Create an array to hold the jobs in execution order */ 
    struct Job *executionOrder[MAX_JOBS * NUM_PRIORITIES];
    int executionIndex = 0;

    while (completedJobs < maxJobs)
    {
        int jobFound = 0; /* Flag to check if a job has been found and executed in this iteration. */ 

        /* Loop through priority levels from highest to lowest */
        for (int priority = 0; priority < NUM_PRIORITIES; priority++)
        {
            /* Loop through all jobs to find the next job with the current priority */
            for (int i = 0; i < maxJobs; i++)
            {
                struct Job *currentJob = &jobRequests[i];

                if (currentJob->priority == priority && currentJob->remaining_cpu_burst > 0)
                {
                    int executeTime;
                    /* Determine time quantum based on priority */
                    if (priority == 0)
                        executeTime = (currentJob->remaining_cpu_burst > TIME_QUANTUM_HIGH)
                                          ? TIME_QUANTUM_HIGH
                                          : currentJob->remaining_cpu_burst;
                    else if (priority == 1)
                        executeTime = (currentJob->remaining_cpu_burst > TIME_QUANTUM_MEDIUM)
                                          ? TIME_QUANTUM_MEDIUM
                                          : currentJob->remaining_cpu_burst;
                    else
                        executeTime = (currentJob->remaining_cpu_burst > TIME_QUANTUM_LOW)
                                          ? TIME_QUANTUM_LOW
                                          : currentJob->remaining_cpu_burst;

                    char message[256];
                    sprintf(message, "Executing Job %d for %d seconds at time %d (Priority %d)\n", currentJob->id, executeTime, currentTime, priority);
                    logToFileAndConsole(message, "log.txt");

                    currentJob->remaining_cpu_burst -= executeTime;
                    currentTime += executeTime;

                    if (currentJob->remaining_cpu_burst == 0)
                    {
                        sprintf(message, "Job %d completed at time %d (Priority %d)\n", currentJob->id, currentTime, priority);
                        logToFileAndConsole(message, "log.txt");
                        completedJobs++;
                    }

                    /* Add the job to the execution order*/
                    executionOrder[executionIndex++] = currentJob;

                    jobFound = 1; /* Set the flag to indicate that a job has been found and executed. */
                    break; /* Break out of the inner loop to recheck priorities. */
                }
            }
        }

        if (!jobFound)
        {
            /* If no job was found to execute in this iteration, increment the time. */
            currentTime++;
        }
    }

    
}

int 
main()
{
    struct Job jobRequests[MAX_JOBS];
    const char *filename = "job_requests.txt";
    /* Read job requests from the file */
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while (i < MAX_JOBS && fscanf(file, "Job %d: CPU Burst %d seconds, I/O Burst %d seconds\n", &jobRequests[i].id, &jobRequests[i].cpu_burst, &jobRequests[i].io_burst) == 3)
    {
        jobRequests[i].remaining_cpu_burst = jobRequests[i].cpu_burst;
        jobRequests[i].priority = rand() % NUM_PRIORITIES; /* Assign a random priority */
        i++;
    }
    fclose(file);
    /* Clear log file at the beginning */
    FILE *logFile = fopen("log.txt", "w");
    fclose(logFile);

    printf("\nGuaranteed Scheduling Scheduler with Priority Levels:\n");
    guaranteedScheduling(jobRequests, i); /* Pass the number of jobs read from the file */

    return (0);
}