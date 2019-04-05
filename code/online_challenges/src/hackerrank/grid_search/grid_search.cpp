#include <iostream>

int main() 
{
    int T, i;
    std::cin >> T;
    for (i = 1;i <= T; ++i) 
    {
        int R, C, r, c, flag = 0, final = 0;
        std::cin >> R >> C;
        char G[R][C];
        
        for (int j = 0; j < R; j++) 
            for (int k = 0;k < C; k++) 
                std::cin >> G[j][k];
        
        std::cin >> r >> c;
        char P[r][c];
        for (int j = 0;j < r; ++j)
            for (int k = 0;k < c; ++k)
                std::cin >> P[j][k];

        for (int j = 0; j < R; ++j) 
        {
            for (int k = 0; k < C; ++k) 
            {   
                if (G[j][k] == P[0][0]) 
                {
                    int flag = 1;
                    if (C-k >= c) 
                    {
                        for (int pr = 0; pr < r; ++pr) 
                        {
                            if (flag == 0)
                                break;  
                            for (int pc = 0; pc < c; ++pc) 
                            {   
                                if (G[j+pr][k+pc] == P[pr][pc])
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