// https://leetcode.com/problems/wiggle-subsequence/

class Solution {
public:
    int wiggleMaxLength(vector<int>& input) 
    {
        int n=input.size();
        int inc=1;
        int dec=1;
        for(int i=1;i<n;i++)
        {
            if(input[i] > input[i-1]) inc = dec+1;
            else if(input[i] < input[i-1]) dec=inc+1;
        }
        return max(inc,dec);
    }
};