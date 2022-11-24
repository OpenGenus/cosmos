/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and 
choosing a different day in the future to sell that stock.

Example :
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/

#include <bits/stdc++.h>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),profit = 0;       
        int buyPrice = prices[0];                            // Initialise Buy Price
        for(int i=1;i<n;i++){
            if(prices[i]>buyPrice) {
                profit = max(profit,prices[i]-buyPrice);     // Update Profit
            }
            else{
                buyPrice = prices[i];                        // If found a lower buyPrice, update it   
            }
        }
        return profit;
    }
};