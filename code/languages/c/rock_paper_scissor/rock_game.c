// Part of Cosmos by OpenGenus
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int generaterandomfunc(int n)
{
    srand(time(NULL));
    return rand() % n;
}
int greater(char char1, char char2)
{
    // return 1 if c1>c2 and 0 otherwise . if c1==c2 it will return -1

    if (char1 == char2)
    {
        return -1;
    }
    else if ((char1 == 'r') && (char2 == 's'))
    {
        return 1;
    }
    else if ((char2 == 'r' && char1 == 's'))
    {
        return 0;
    }

    else if ((char1 == 'p') && (char2 == 'r'))
    {
        return 1;
    }
    else if ((char2 == 'p') && (char1 == 'r'))
    {
        return 0;
    }

    else if ((char1 == 's') && (char2 == 'p'))
    {
        return 1;
    }
    else if ((char2 == 's') && (char1 == 'p'))
    {
        return 0;
    }
}

int main()
{
    int playerscore = 0, compscore = 0, temp;
    char playerchar, compchar;
    char dict[45] = {'r', 'p', 's'};
    printf("welcome to the rock paper scissor game\n");

    for (int i = 0; i < 3; i++)

    {
        printf("choose 1 for rock choose 2 for paper choose 3 for scissor \n");
        printf("player no.1 turn \n");
        scanf("%d", &temp);
        playerchar = dict[temp - 1];
        printf("you choose  %c\n", playerchar);

        printf("choose 1 for rock choose 2 for paper choose 3 for scissor \n");
        printf("player no.1 turn \n");
        temp = generaterandomfunc(3) + 1;
        compchar = dict[temp - 1];
        printf("cpu choose  %c\n", compchar);
        if (greater(compchar, playerchar) == 1) //compchar is greater than player char
        {
            compscore += 1;
            printf("cpu got it hurray\n");
        }
        else if (greater(compchar, playerchar) == -1)
        {
            compscore += 1;
            playerscore += 1;
            printf("its a draw \n");
        }
        else
        {
            playerscore += 1;
            printf("you got it hurray\n");
        }

        printf("you : %d \ncpu : %d \n", playerscore, compscore);
    }
    if (playerscore > compscore)
    {
        printf("you win \n");
    }
    else if (compscore > playerscore)
    {
        printf("cpu win \n");
    }
    else
    {
        printf("match is draw");
    }
    return 0;
}
