// https://leetcode.com/problems/perfect-squares/

class Solution {
public:
    
    int helper(int n,vector<int> &dp){
        if(n == 0) return 0; // base case
        
        if(dp[n] != -1) return dp[n];
        
        int ans = 1e8;
        
        for(int i=1;i*i<=n;i++){
            int calc = 1 + helper(n - (i*i),dp);
            ans = min(ans , calc);
        }
        return dp[n] = ans;
    }
        
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};