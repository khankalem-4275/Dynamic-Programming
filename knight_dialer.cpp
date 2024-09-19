// https://leetcode.com/problems/knight-dialer/

class Solution {
public:
    
    int mod = 1e9 + 7;
    
    vector<vector<int>> vec = {{4,6} , {8,6} , {7,9} , {4,8} ,{0,3,9} , {} , {1,7,0} , {2,6} ,{1,3} ,                                     {2,4}};
    
    int solve(int start , int len , int n , vector<vector<int>> &dp){
        if(len == n) return 1;
        
        if(dp[start][len] != -1) return dp[start][len];
        
        int temp = 0;
        for(auto ele : vec[start]){
            temp = (temp + solve(ele ,len + 1 ,n, dp)) % mod;
        }
        return dp[start][len] = temp;
    }
    
    int knightDialer(int n) {
        int ans = 0;
        
        // changing parameters => start , len
        vector<vector<int>> dp(10,vector<int> (n+1,-1));
        
        for(int i=0;i<10;i++){
            ans = (ans + solve(i , 1,n,dp) % mod)%mod;
        }
        return ans;
    }
};