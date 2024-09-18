// https://leetcode.com/problems/divisor-game/

class Solution {
public:
    
    bool solve(int n , vector<bool> &dp){
        
        if(dp[n] == true) return dp[n];
        
        for(int i=1;i<n;i++){
            if(n%i == 0 && !solve(n-i,dp)){
                return dp[n] = true;
            }
        }
        return dp[n] = false;
    }
    
    bool divisorGame(int n) {
        // changing parameters => n
        vector<bool> dp(n,false);
        return solve(n,dp);
    }
};