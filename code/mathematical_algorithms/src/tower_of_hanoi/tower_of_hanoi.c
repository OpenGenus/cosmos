#include <stdio.h>
// Part of Cosmos by OpenGenus Foundation
int moves = 0;
void hanoi(int disks, char A, char B, char C);
 
int 
main()
{
    int n; // Number of disks
    printf("Enter the number of disks- ");
    scanf("%d", &n);

    hanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods
    printf("Total moves- %d\n", moves);

    return (0);
}

void 
hanoi(int disks, char A, char B, char C)
{
    moves++;
    if (disks==1) {
        printf("Move disk 1 from rod %c to rod %c \n", A, B);
        return;
    }
    hanoi(disks -1 , A, C, B);
    printf("Move disk %d from rod %c to rod %c \n", disks, A, B);
    hanoi(disks - 1, C, B, A);
}
