// https://leetcode.com/problems/word-break/

class Solution {
public:
    
    bool solve(int index , string &s , unordered_set<string> &st , int n,
              vector<int> &dp){
        if(index >= n) return true;
        
        if(st.find(s) != st.end()){
            return true;
        }
        
        if(dp[index] != -1) return dp[index];
        
        for(int i=1;i<=n;i++){
            
            string temp = s.substr(index , i);
            
            if(st.find(temp) != st.end() && solve(index+i,s,st,n,dp)){
                return dp[index] = true;
            }
        }
        
        return dp[index] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        
        // changing parameters => index
        
        vector<int> dp(n,-1);
        
        unordered_set<string> st;
        for(auto ele : wordDict) st.insert(ele);
        
        return solve(0,s,st,n,dp);
    }
};