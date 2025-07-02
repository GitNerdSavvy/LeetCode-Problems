class Solution {
public:
    void paths(TreeNode* root,vector<int>v,int sum,vector<vector<int>>&grid){
        if(!root) return;
        if(!root->left && !root->right){
            if(root->val==sum){
                v.push_back(root->val);
                grid.push_back(v);
            }
            return;
        }
        v.push_back(root->val);
        paths(root->left,v,sum-(root->val),grid);
        paths(root->right,v,sum-(root->val),grid);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>grid;
        vector<int>ans;
        paths(root,ans,targetSum,grid);
        return grid;
    }
};