// https://leetcode.com/problems/video-stitching/?envType=problem-list-v2&envId=dynamic-programming&difficulty=MEDIUM

class Solution {
public:
    
    bool static comparator(vector<int> &a , vector<int> &b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();
        int maxReach = 0;
        int i = 0;
        int count = 0;
        
        sort(clips.begin(),clips.end(),comparator);
        
        while(maxReach < time){
            int currMaxReach = 0;
            
            while(i < n && clips[i][0] <= maxReach){
                currMaxReach = max(currMaxReach , clips[i][1]);
                i++;
            }
            
            if(currMaxReach <= maxReach) return -1; // cannot move further
            maxReach = currMaxReach;
            count++;
        }
        
        return count;
    }
};