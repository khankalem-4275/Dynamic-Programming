// https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    
    int solve(int index , vector<int> &cost , int n, vector<int> &dp){
        if(index >= n) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int a = solve(index+1,cost,n,dp) + cost[index];
        int b = solve(index+2,cost,n,dp) + cost[index];
        
        return dp[index] = min(a,b);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return min(solve(0,cost,n,dp) , solve(1,cost,n,dp));
    }
};