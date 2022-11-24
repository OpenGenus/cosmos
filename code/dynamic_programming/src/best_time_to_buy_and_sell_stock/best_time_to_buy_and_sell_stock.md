# Best Time to Buy and Sell Stock
This is a very famous of set of problems with multiple variations making it harder with each variation
The most famous variations are as follows :
- [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
- [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)
- [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)
- [Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)
- [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)
- [Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

Let's explore them one by one

## [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
This question is the most naive of the series and very straight forward.
The question goes as follows :
```cpp
    You are given an array prices where prices[i] is the price of a given stock on the ith day.
    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
    Example :
    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
```
The approach is very simple, it is as follows : 
- Iterative through the array of stocks for every and update your buy price to lowest local price
- Whenever you encounter a selling price greater than the buyPrice, then update profit

Time complexity
---------------
Worst case: O(n), where n is the number of elements in the array of stocks

Space complexity
----------------
O(1) - Constant Extra Space

## [Best Time to Buy and Sell Stock II ](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)
The question goes as follows :
```cpp
    You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
    On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
    Example :
    Input: prices = [7,1,5,3,6,4]
    Output: 7
    Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
    Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
    Total profit is 4 + 3 = 7
```
So in this question we can trade **multiple times** but **cannot** be holding **more than one stock** at a time!
The approach is as follows : 
- Iterative through the array of stocks for every time ```cpp stockPrices[i] > stockPrices[i-1]```, update the profit as ```cpp profit = profit + stockPrices[i] - stockPrices[i-1] ```.
- This is because buy and selling everyday (when there is an increase) is equivalent to buying and selling at local maxima.
- To understand this better let's take an example : 
    - Let ```cpp [1,2,3,4,5]``` be a local monotonic increasing sequence of a bigger array of stock prices, then
    - If we buy and sell every day : 
        - Profit = (2-1) + (3-2) + (4-3) + (5-4) = 1 + 1 + 1 + 1 = 4
    - If we buy at 0 index and sell at index-4 :
        - Profit = 5 - 1 = 4

Time complexity
---------------
Worst case: O(n), where n is the number of elements in the array of stocks

Space complexity
----------------
O(1) - Constant Extra Space
