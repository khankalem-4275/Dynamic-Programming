// https://leetcode.com/problems/minimum-cost-for-tickets/

class Solution {
public:
    
    int solve(int index , vector<int> &days , vector<int> &costs , int n , vector<int> &dp){
        if(index >= n) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int a = costs[0] + solve(index+1,days,costs,n,dp);
        
        int i = index;
        while(i < n && days[i] < days[index] + 7) i++;
        
        int b = costs[1] + solve(i,days,costs,n,dp);
        
        int j = index;
        while(j < n && days[j] < days[index] + 30) j++;
        
        int c = costs[2] + solve(j,days,costs,n,dp);
        
        return dp[index] = min(a,min(b,c));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        
        // changing parameters => index
        vector<int> dp(n+1,-1);
        
        return solve(0,days,costs,n,dp);
    }
};