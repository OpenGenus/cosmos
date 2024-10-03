#include <iostream>
#include <limits.h>
using namespace std;

//Utility Function
int sum(int freq[], int i, int j){
    int s = 0;
    for(int k=i; k<=j; k++)
        s += freq[k];
    return s;
}

int obst(int keys[], int freq[], int n){
    int cost[n][n];

    /* cost[i][j] = optimal cost of bst
     * that can be formed from
     * keys[i] to keys[j].
     * cost[0][n-1] will store the
     * resultant cost
     */

    //For single key cost=freq of the key
    for(int i=0; i<n; i++){
        cost[i][i] = freq[i];
    }

    //Now we need to consider chain of
    //lengths 2, 3, ...
    //L is chain length
    for(int L=2; L<=n; L++){
        // i is row number in cost[][]
        for(int i=0; i<=n-L+1; i++){
            //Get max col number j from
            //row num i and chain len L
            int j = i+L-1;
            cost[i][j] = INT_MAX;

            //Try making all keys in
            //interval keys[i..j] as root
            for(int r=i; r<=j; r++){
                
                //c = cost when keys[r]
                //becomes root of this
                //subtree
                int c = ((r>i)?cost[i][r-1]:0) +
                        ((r<j)?cost[r+1][j]:0) +
                         sum(freq,i,j);
                if(c < cost[i][j])
                    //cout r if we want structure
                    //of obst
                    cost[i][j] = c;
            }
        }
    }
    return cost[0][n-1];
}
/* O(n^4) 
 * can be reduced to O(n^3) by precalculating
 * sum of all freq instead of calling sum
 * again and again
 */
int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys)/sizeof(keys[0]);
    cout << "Cost of OBST: "
         << obst(keys, freq, n) << endl;
    return 0;
}
