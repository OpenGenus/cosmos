## backtracking algorithm for Knight tour
if you do not know what backtacking is please [visit](https://www.geeksforgeeks.org/backtracking-introduction/) and have an idea about it.
### let's go :cowboy_hat_face:
So we have to cover all the blocks in chess.
lets first start with how knight moves in chess (yes you are right) ** ek do dai ** :p
```cpp
    int xMove[8] = {  2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = {  1, 2, 2, 1, -1, -2, -2, -1 };
```  
above code is storing all the possible moves for knight.

![Image of knight moves](https://www.brainbashers.com/gifs/knightsmove.gif)

and we are initializing matrix to -1 ...it represents initially all blocks are unvisited.
```cpp
 /* Initialization of solution matrix */
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;
```
and now we will be starting from 0,0 and we will explore all the blocks in chess (wonderlust :rofl: )
now comes the main thing. 
### Algorithm
> * If all squares are visited
    print the solution
> * Else
>   * a) Add one of the next moves to solution vector and recursively 
    check if this move leads to a solution. (A Knight can make maximum 
   eight moves. We choose one of the 8 moves in this step).
>   * b) If the move chosen in the above step doesn't lead to a solution
   then remove this move from the solution vector and try other 
   alternative moves.
>   * c) If none of the alternatives work then return false (Returning false 
   will remove the previously added item in recursion and if false is 
   returned by the initial call of recursion then "no solution exists" )

implementation of above algorithm
```cpp
 if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == false) //hey! programmer i tried my best but could not find the way
    {
        printf("Solution does not exist");
        return false;
    }
    else
        printSolution(sol); //I did it bro
    return true;
```
now you all must be thinking what solveKTUtil is.
```cpp
/* A recursive utility function to solve Knight Tour
 * problem */
int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[N], int yMove[N])
```

x and y are coordinate, movei is number of move,sol[][N] is solution matrix, and you already know what xmove and ymove is :sunglasses:


```cpp 
int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[N], int yMove[N])
{
    int k, next_x, next_y;
    if (movei == N * N)
        return true;   //if number of moves equal to the numer of blocks in chess then yay! we traced all the blocks bruh

    /* Try all next moves from the current coordinate x, y */
    for (k = 0; k < 8; k++)
    {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol))
        {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol,
                            xMove, yMove) == true)
                return true; // if move was right then we must return from here and go back to print the solution
            else
                sol[next_x][next_y] = -1; // backtracking ..just go back we took wrong way lets now try another way 
        }
    }
    return false; // if nothing can be done
}
```
next_x and next_y will provide next move for knight 
now what isSafe(next_x,next_y,sol) is ???
so basic safety is not to fall from the chess board :p yes we have to teach this too :p


```cpp
bool isSafe(int x, int y, int sol[N][N])
{
    return x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1;//ofcorse it should unvisited
 }
```

now what else is left .. no please do that by yourself ... ok just take that too
```cpp
void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
}
```
## Yay! we did that :sunglasses:


   
