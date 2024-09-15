// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int minCost = prices[0];
        for(int i=1;i<n;i++){
            profit = max(profit , prices[i] - minCost);
            minCost = min(minCost , prices[i]);
        }
        return profit;
    }
};