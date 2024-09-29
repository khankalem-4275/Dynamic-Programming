// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/?envType=problem-list-v2&envId=dynamic-programming&difficulty=MEDIUM

class Solution {
public:
    
    int solve(int index , int buy , vector<int> &prices , int n,
             vector<vector<int>> &dp){
        if(index >= n) return 0;
        
        if(dp[index][buy] != -1) return dp[index][buy];
        
        if(buy){
            return dp[index][buy] = max(-prices[index] + solve(index+1,0,prices,n,dp) ,
                      solve(index+1,1,prices,n,dp));
        }
        return dp[index][buy] = max(prices[index] + solve(index+2,1,prices,n,dp),
                  solve(index+1,0,prices,n,dp));
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // changing parameters => index , buy 
        vector<vector<int>> dp(n+2,vector<int> (2,-1));
        return solve(0,1,prices,n,dp);
    }
};