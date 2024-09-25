// https://leetcode.com/problems/house-robber-iii/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    unordered_map<TreeNode * , int> mp;
    
    int solve(TreeNode *root){
        if(root == NULL) return 0; // base case
        
        if(mp.find(root) != mp.end() && mp[root] != -1){
            return mp[root];
        }
        mp[root] = -1;
        
        // try out all possibilities
        int pickUp = 0;
        int notPickUp = 0;
        if(root->left != NULL){
            pickUp = pickUp + solve(root->left->left) + solve(root->left->right);
        }
        if(root->right != NULL){
            pickUp = pickUp + solve(root->right->right) + solve(root->right->left);
        }
        pickUp = pickUp + root->val;
        notPickUp = solve(root->left) + solve(root->right);
        
        return mp[root] = max(pickUp , notPickUp);
    }
    
    int rob(TreeNode* root) {
        return solve(root);
    }
};