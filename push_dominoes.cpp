// https://leetcode.com/problems/push-dominoes/

class Solution {
public:
    string pushDominoes(string s) {
      int n=s.length();
        vector<int> left(n,0);
        vector<int> right(n,0);

        char prev='.';
        int time=1;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='R')
            {
                prev='R';
                time=1;
                continue;
            }
            else if(s[i]=='L')
            {
                prev='L';
            }
            else if(s[i]=='.' && prev=='R')
            {
                right[i]=time;
                time++;
            }
        }

        prev='.';
        time=1;

        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='L')
            {
                prev='L';
                time=1;
                continue;
            }
            else if(s[i]=='R')
            {
                prev='R';
            }
            else if(prev=='L' && s[i]=='.')
            {
                left[i]=time;
                time++;
            }
        }

        string ans="";
        for(int i=0;i<n;i++)
        {
            if(left[i]==right[i])
            {
                ans.push_back(s[i]);
            }
            else if(left[i]==0)
            {
                ans.push_back('R');
            }
            else if(right[i]==0)
            {
                ans.push_back('L');
            }
            else if(left[i] < right[i])
            {
                ans.push_back('L');
            }
            else if(left[i] > right[i])
            {
                ans.push_back('R');
            }
        }
        return ans;
    }
};