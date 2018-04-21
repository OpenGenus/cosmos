/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 
 * Author:- Rishav Pandey
 * Part of Cosmos by OpenGenus Foundation
 */

#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
int move(int tile);
int won(void);

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
               DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (1)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: (0)exit ");
        int tile;
        scanf("%d", &tile);

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // TODO

    int tiles = (d * d - 1);
    for (int i = 0; i < d; i++)
        for (int j = 0; j < d; j++)
        {
            board[i][j] = tiles;
            tiles--;
        }

    // to swap the second last and third last index of board when d is even.
    if (d % 2 == 0)
    {
        int temp = board[d - 1][d - 3];
        board[d - 1][d - 3] = board[d - 1][d - 2];
        board[d - 1][d - 2] = temp;
    }
}
/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (!board[i][j])
            {
                printf(" _ ");
            }
            else
            {
                printf("%2i ", board[i][j]);
            }
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
int move(int tile)
{
    // TODO
    // For keeping the track of tile in the Game
    int row, column;
    for (int i = 0; i < d; ++i)
    {
        for (int j = 0; j < d; ++j)
        {
            if (board[i][j] == tile)
            {
                row = i;
                column = j;
            }
        }
    }
    
    // For keeping the track of blank tile in the Game
    int row1, column1;
    for (int i = 0; i < d; ++i)
    {
        for (int j = 0; j < d; ++j)
        {
            if (board[i][j] == 0)
            {
                row1 = i;
                column1 = j;
            }
        }
    }

    // For legal move of the tile towards Right
    if (board[row][column] == board[row1][column1 + 1])
    {
        board[row1][column1 + 1] = 0;
        board[row1][column1] = tile;
        return 1;
    }
    //usleep(15000000);
    // For legal move of the tile towards Left
    if (board[row][column] == board[row1][column1 - 1])
    {
        board[row1][column1 - 1] = 0;
        board[row1][column1] = tile;
        return 1;
    }
    // For legal move of the tile towards Up
    if (board[row][column] == board[row1 - 1][column1])
    {
        board[row1 - 1][column1] = 0;
        board[row1][column1] = tile;
        return 1;
    }
    // For legal move of the tile towards Down
    if (board[row][column] == board[row1 + 1][column1])
    {
        board[row1 + 1][column1] = 0;
        board[row1][column1] = tile;
        return 1;
    }
    return 0;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
int won(void)
{
    // TODO
    int counter = 0;

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            //++counter != (d*d) checks from starting to second last tile.
            //board[i][j] != counter returns false if values are incorrect.
            if (++counter != (d * d) && board[i][j] != counter)
            {
                return 0;
            }
        }
    }

    return 1;
}
