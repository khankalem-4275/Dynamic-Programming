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


// using memoization

class Solution {
public:
    
    int solve(int index , int buy , vector<int> &prices , int n,
             vector<vector<int>> &dp){
        if(index == n) return 0;
        
        int profit = 0;
        
        if(dp[index][buy] != -1) return dp[index][buy];
        
        if(buy){
            profit = max(-prices[index] + solve(index+1,0,prices,n,dp) ,
                         solve(index+1,1,prices,n,dp));
        }
        else{
            profit = max(prices[index] + solve(index+1,1,prices,n,dp) ,
                         solve(index+1,0,prices,n,dp));
        }
        
        return dp[index][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        // changing parameters => index , buy
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,n,dp);
    }
};