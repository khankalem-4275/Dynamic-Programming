// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/?envType=problem-list-v2&envId=dynamic-programming&difficulty=MEDIUM

class Solution {
public:
    // tabulation method
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n+1,vector<int> (2,0));
        // base condition
        dp[n][0] = 0;
        dp[n][1] = 0;
        
        // changing parameters => (index , buy)
        for(int index = n-1;index >= 0;index--){
            for(int buy = 0;buy <= 1;buy++){
                // copy the recurrence
                int profit = 0;
                if(buy){
                    profit = max(-prices[index] + dp[index+1][0] , dp[index+1][1]);
                }
                else{
                    profit = max(prices[index] + dp[index+1][1] , dp[index+1][0]);
                }
                dp[index][buy] = profit;
            }
        }
        
        return dp[0][1];
    }
};