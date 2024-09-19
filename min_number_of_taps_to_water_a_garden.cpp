// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

class Solution {
public:
    
    int solve(int index , vector<pair<int,int>> &vec , int n , vector<int> &dp){
        
        if(vec[index].second == n) return 1;
        if(index >= vec.size()) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int ans = 1e8;
        
        // try out all the possible combinations
        for(int i = index + 1 ; i < vec.size() ; i++){
            if(vec[i].first > vec[index].second) break;
            ans = min(ans , 1 + solve(i ,vec ,n , dp));
        }
        
        return dp[index] = ans;
    }
    
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> vec;
        for(int i=0;i<ranges.size();i++){
            vec.push_back({max(0 , i - ranges[i]) , min(n , i + ranges[i])});
        }
        
        // changing parameters => index
        vector<int> dp(ranges.size() + 1 , -1);
        
        sort(vec.begin() , vec.end()); // basis of starting time
        int ans = 1e8;
        
        for(int i=0;i<vec.size();i++){
            if(vec[i].first == 0){
                ans = min(ans , solve(i , vec ,n , dp));
            }
        }
        
        return ans == 1e8 ? -1 : ans;
    }
};