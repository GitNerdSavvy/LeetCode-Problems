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
        return 1 + max(levels(root->left),levels(root->right));
    }
    void nth(TreeNode* root,int curr,int i,vector<int>&v){
            if(!root) return;
            if(curr==i){
                v[curr]=max(v[curr],root->val);
                return;
            }
            nth(root->left,curr+1,i,v);
            nth(root->right,curr+1,i,v);
    }
    vector<int> largestValues(TreeNode* root) {
        int n=levels(root);
        vector<int>ans(n,INT_MIN);
        for(int i=0;i<n;i++){
            nth(root,0,i,ans);
        }
        return ans;
    }
};