// https://leetcode.com/problems/filling-bookcase-shelves/

class Solution {
public:
    
    int solve(int index , vector<vector<int>> &books , int shelfWidth , int height , 
              int totalShelfWidth , vector<vector<int>> &dp){
        
        if(index == books.size()) return height;
        
        if(dp[index][shelfWidth] != -1) return dp[index][shelfWidth];
        
        int a = INT_MAX;
        int b = INT_MAX;
        
        if(shelfWidth >= books[index][0]){
            a = solve(index+1,books,shelfWidth - books[index][0] , max(height,books[index][1]) , 
                      totalShelfWidth ,dp);
        }
        
        b = height + solve(index+1,books,totalShelfWidth - books[index][0] , books[index][1] , totalShelfWidth , dp);
        
        return dp[index][shelfWidth] = min(a,b);
    }
    
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        
        // changing parameters => index , shelfWidth
        vector<vector<int>> dp(books.size() + 1 , vector<int> (shelfWidth + 1,-1));
        return solve(0,books,shelfWidth,0,shelfWidth,dp);
    }
};