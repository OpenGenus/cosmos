#include <iostream>

int main() 
{
    int t;
    std::cin >> t;
    for (int i = 1;i <= t; ++i) 
    {
        int row, col, r, c, final = 0;
        std::cin >> row >> col;
        char G[row][col];
        
        for (int j = 0; j < row; ++j) 
            for (int k = 0; k < col; ++k) 
                std::cin >> G[j][k];
        
        std::cin >> r >> c;
        char P[r][c];
        for (int j = 0;j < r; ++j)
            for (int k = 0;k < c; ++k)
                std::cin >> P[j][k];

        for (int j = 0; j < row; ++j) 
        {
            for (int k = 0; k < col; ++k) 
            {   
                if (G[j][k] == P[0][0]) 
                {
                    int flag = 1;
                    if (col - k >= c) 
                    {
                        for (int pr = 0; pr < r; ++pr) 
                        {
                            if (flag == 0)
                                break;  
                            for (int pc = 0; pc < c; ++pc) 
                            {   
                                if (G[j + pr][k + pc] == P[pr][pc])
                                {
                                    if (pr == r - 1 && pc == c - 1)
                                        final = 1;
                                    flag = 1;
                                } 
                                else 
                                {   
                                    flag = 0;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        if(final)
            std::cout << "YES" << "\n";
        else 
            std::cout << "NO" << "\n";
    }

    return 0;

}
