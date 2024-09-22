// https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int dp[101][101]{}; // initialising an empty array..
    int uniquePaths(int m, int n,int i=0,int j=0) {
        if(i>=m || j>=n) return 0;
        else if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]) return dp[i][j];
        return dp[i][j] = uniquePaths(m,n,i,j+1) + uniquePaths(m,n,i+1,j);
    }
};