// https://leetcode.com/problems/minimum-cost-for-cutting-cake-i/?envType=problem-list-v2&envId=dynamic-programming&difficulty=MEDIUM

class Solution {
public:
    
    int solve(int si,int sj,int ei,int ej,vector<int> &hcut,vector<int> &vcut,
             int dp[21][21][21][21]){
        if((ei - si) == 1 && (ej - sj) == 1) return 0;
        
        int ans = 1e8;
        
        if(dp[si][sj][ei][ej] != -1) return dp[si][sj][ei][ej];
        
        for(int i = si+1;i<ei;i++){
            int cost = hcut[i-1] + solve(si,sj,i,ej,hcut,vcut,dp) + solve(i,sj,ei,ej,hcut,vcut,dp);
            ans = min(ans ,cost);
        }
        
        for(int i=sj+1;i<ej;i++){
            int cost = vcut[i-1] + solve(si,sj,ei,i,hcut,vcut,dp) + solve(si,i,ei,ej,hcut,vcut,dp);
            ans = min(ans , cost);
        }
        
        return dp[si][sj][ei][ej] = ans;
    }
    
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        
        // changing parameters => si,sj,ei,ej
        int dp[21][21][21][21];
        memset(dp,-1,sizeof(dp));
        
        return solve(0,0,m,n,horizontalCut,verticalCut,dp);
    }
};