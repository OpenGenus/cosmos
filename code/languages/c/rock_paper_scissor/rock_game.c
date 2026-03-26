#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate random choice: 0, 1, or 2
int generateRandom(int n)
{
    return rand() % n;
}

// Returns:
//  1  -> first wins
//  0  -> second wins
// -1  -> draw
int compare(char p1, char p2)
{
    if (p1 == p2)
        return -1;

    if ((p1 == 'r' && p2 == 's') ||
        (p1 == 'p' && p2 == 'r') ||
        (p1 == 's' && p2 == 'p'))
        return 1;

    return 0;
}

int main()
{
    int playerScore = 0, cpuScore = 0;
    int choice;
    char playerChar, cpuChar;
    char options[] = {'r', 'p', 's'};

    srand(time(NULL)); // seed ONCE

    printf("Welcome to Rock Paper Scissors Game 🎮\n");

    for (int i = 0; i < 3; i++)
    {
        printf("\nRound %d\n", i + 1);
        printf("Choose:\n1. Rock\n2. Paper\n3. Scissors\n");
        scanf("%d", &choice);

        if (choice < 1 || choice > 3)
        {
            printf("Invalid choice! Try again.\n");
            i--;
            continue;
        }

        playerChar = options[choice - 1];
        cpuChar = options[generateRandom(3)];

        printf("You chose: %c\n", playerChar);
        printf("CPU chose: %c\n", cpuChar);

        int result = compare(playerChar, cpuChar);

        if (result == 1)
        {
            printf("You win this round! 🎉\n");
            playerScore++;
        }
        else if (result == 0)
        {
            printf("CPU wins this round 🤖\n");
            cpuScore++;
        }
        else
        {
            printf("It's a draw 🤝\n");
        }

        printf("Score → You: %d | CPU: %d\n", playerScore, cpuScore);
    }

    printf("\nFinal Result:\n");
    if (playerScore > cpuScore)
        printf("You won the game 🏆\n");
    else if (cpuScore > playerScore)
        printf("CPU won the game 🤖\n");
    else
        printf("Game is a draw 🤝\n");

    return 0;
}
