#include <stdio.h>
#include <string.h>
#include "mpi.h"
#include <math.h>

double
trap_value(double h, double x0, double x1)
{
        return (h / 2.0) * (pow(x0, 2) + pow(x1 ** 2));
}

int
main (int argc, char* argv[])
{
    int my_rank;
    int p;  //Total number of processess
    int source;
    int dest;
    double message;
    int tag = 0;    //Provide an integer value to message
    MPI_Status status;  //Used on receiver's side

    static double sum = 0;
    //printf("Sum init %f\n", sum);

    MPI_Init(&argc, &argv); //Creates an environment of definite processes (Code goes parallel from here)
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); //Assign rank to each processes (fetches rank from MPI_COMM_WORLD)
    MPI_Comm_size(MPI_COMM_WORLD, &p); //Assigns number of processes to p

    if(my_rank != 0)
    {
        dest = 0;   //Send message to rank-0 process
        double h = (1.2 - 0.0) / p;
        double a = h * (my_rank - 1);
        double b = h * (my_rank);
        message = trap_value(h, a, b);
        printf("Sent message %f\n", message);
        MPI_Send(&message, 10, MPI_INT, dest, tag, MPI_COMM_WORLD);
    }
    else
    {
        for(source = 1; source < p; source++)
        {
            MPI_Recv(&message, 10, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
           // printf("Received %f\n", message);
            sum += message;
        }

        printf("The sum is %f\n", sum);
    }

    MPI_Finalize();

}
