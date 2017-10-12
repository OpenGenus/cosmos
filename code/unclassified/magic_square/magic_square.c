// Part of Cosmos by OpenGenus Foundation

#include<stdio.h>
#include<string.h>
 
void MagicSquare(int n)
{
    int magic[n][n],num;

    memset(magic, 0, sizeof(magic));
 
    // Initialize position for 1
    int i = n/2;
    int j = n-1;
 
    // One by one put all values in magic square
    for(num = 1; num <= n*n; )
    {
        if (i==-1 && j==n)
        {
            j = n-2;
            i = 0;
        }
        else
        {
            // if next number goes to out of square's right side
            if (j == n)
                j = 0;
            //if next number goes to out of square's upper side
            if (i < 0)
                i=n-1;
        }
        if (magic[i][j])
        {
            j -= 2;
            i++;
            continue;
        }
        else
            magic[i][j] = num++; //set number
 
        j++; i--;
    }
 
    // Print magic square
    printf("The Magic Square for n=%d:\nSum of each row or column %d:\n\n",
            n, n*(n*n+1)/2);
    
    for(i=0; i < n; i++)
    {
        for(j=0; j < n; j++)
            printf("%3d ", magic[i][j]);
        printf("\n");
    }
}
 
int main()
{
    int n = 7; // Works only when n is odd
    MagicSquare(n);
    return 0;
}
