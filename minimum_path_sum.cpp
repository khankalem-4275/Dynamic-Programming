// https://leetcode.com/problems/minimum-path-sum/?envType=problem-list-v2&envId=dynamic-programming&difficulty=MEDIUM

class Solution {
public:
    
    int solve(int row , int col , vector<vector<int>> &nums , int n , int m,
             vector<vector<int>> &dp){
        
        if(row == n || col == m) return INT_MAX/2;
        if(row == n-1 && col == m-1) return nums[row][col];
        
        if(dp[row][col] != -1) return dp[row][col];
        
        int a = nums[row][col] + solve(row,col+1,nums,n,m,dp);
        int b = nums[row][col] + solve(row+1,col,nums,n,m,dp);
        
        return dp[row][col] = min(a ,b);
    }
    
    int minPathSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        
        // changing parameters => row , col
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        
        return solve(0,0,nums,n,m,dp);
    }
};