// https://leetcode.com/problems/maximum-earnings-from-taxi/?envType=problem-list-v2&envId=dynamic-programming&difficulty=MEDIUM

class Solution {
public:
    
    long long solve(int index , vector<vector<int>> &rides,
                   vector<long long> &dp){
        
        if(index >= rides.size()) return 0;

        if(dp[index] != -1) return dp[index];
        
        long long a = 0;
        long long b = 0;
        
        auto it = lower_bound(rides.begin() , rides.end() , rides[index][1] ,
                             [](vector<int> &vec , int value){
                                 return vec[0] < value; // write false condition here
                             });
        
        a = rides[index][1] - rides[index][0] + rides[index][2] + solve(it - rides.begin(),rides,dp);
        
        b = solve(index+1,rides,dp);
        
        return dp[index] = max(a,b);
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin() , rides.end());
        // // changing parameters => index
        vector<long long> dp(rides.size(), -1);
        return solve(0,rides,dp);
    }
};