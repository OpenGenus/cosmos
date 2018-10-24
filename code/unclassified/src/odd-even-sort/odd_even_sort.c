#include <stdio.h>
#include<math.h>
#include "mpi.h"

void
swap(int array[], int i, int j)
{
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
}

int
main(int argc, char** argv)
{
        int my_rank, p, res, dest = 0, tag = 0, i;

        int array[8] = {9, 2, 1, 3, 5, 4, 6, 7};
        int n = 8;

        MPI_Status status;
        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
        MPI_Comm_size(MPI_COMM_WORLD, &p);

        int k = ceil(n / 2.0);

        for(i = 0; i < k; i += 1)
        {
                if(my_rank == p - 1)
                {

                }
                else
                {
                        for(int j = 0; j < n; j += 2)
                        {
                                if(array[j] > array[j + 1])
                                        swap(array, j, j + 1);
                        }
                        for(int j = 1; j < n - 1; j += 2)
                        {
                                if(array[j] > array[j + 1])
                                        swap(array, j, j + 1);
                        }
                }
        }

        MPI_Finalize();

        if(my_rank == 0)
        {
                for(int j = 0; j < n; j += 1)
                        printf("%d ", array[j]);
                printf("\n");
        }
}
