/* Part of Cosmos by OpenGenus Foundation */

/* 
**
** @AUTHOR: VINAY BADHAN
** @GREEDY PROBLEM: MINIMUM COINS
** @GITHUB LINK: https://github.com/vinayb21
*/
 
// Part of Cosmos by OpenGenus Foundation
import java.util.*;

class MinCoinsGreedy {
    
    // It is assumed that coins array is sorted in descending order
    
    public static int minCoins(int amount, int[] coins)
    {
        int n,minCount,i,j;
        minCount = 0;
        n = coins.length;
        while(amount>0)
        {
            for(i=0;i<n;i++)
            {
                if(amount>=coins[i])
                {
                    amount -= coins[i];
                    minCount++;
                    break;
                }
            }
        }
        return minCount;
    }
    

    public static void main(String[] args) {
        int[] coins = {20,10,5,2,1};
        int amount = 55;
        int ans = minCoins(amount, coins);
        System.out.println("Minimum number of coins "+ ans);
    }
}
