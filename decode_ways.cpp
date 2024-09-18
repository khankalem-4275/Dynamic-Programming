// https://leetcode.com/problems/decode-ways/

class Solution {
public:
    
    int solve(int index, string s , int n , vector<int> &dp){
        
        if(s[index] == '0') return 0;
        if(index == n-1 || index == n)  return 1;
        
        if(dp[index] != -1) return dp[index];
        
        int a = 0;
        int b = 0;
        a = solve(index+1,s,n,dp);
        string temp = s.substr(index,2);
        if(stoi(temp) > 0 && stoi(temp) <= 26) b = solve(index+2,s,n,dp);
        
        return dp[index] = a + b;
    }
    
    int numDecodings(string s) {
        int n = s.size();
        
        // changing parameters => index;
        vector<int> dp(n,-1);
        
        return solve(0,s,n,dp);
    }
};