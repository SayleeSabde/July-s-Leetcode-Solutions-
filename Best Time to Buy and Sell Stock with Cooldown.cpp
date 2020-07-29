/*Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<= 1)
            return 0;
        int prev_buy = 0,prevSell = 0;
        int endWithSell = 0;
        int endWithBuy = INT_MIN;
        for(int i = 0;i < prices.size();i++) {
           prev_buy = endWithBuy;
           endWithBuy = max(endWithBuy,prevSell- prices[i]);
           prevSell = endWithSell;
           endWithSell = max(endWithSell,prev_buy+ prices[i]);
        }
        return endWithSell;
        
        
    }
};