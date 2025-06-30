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
    int levels(TreeNode* root){
        if(!root) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void love(TreeNode* root,int level,int curr,vector<int>&ans){
        if(!root)return;
        if(curr==level){
            ans.push_back(root->val);
            return;
        }
        love(root->left,level,curr+1,ans);
        love(root->right,level,curr+1,ans);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int n=levels(root);
        vector<vector<int>>res;
        for(int i=n-1;i>=0;i--){
            vector<int>ans;
            love(root,i,0,ans);
            res.push_back(ans);
        }
        return res;
    }
};