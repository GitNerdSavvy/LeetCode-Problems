class Solution {
public:
    int level(TreeNode* root){
        if(!root) return 0;
        return 1+max(level(root->left),level(root->right));
    }
    void levelwise(TreeNode* root,int level,int curr,vector<int>&ans){
        if(!root) return;
        if(curr==level){
            ans.push_back(root->val);
            return;
        }
        levelwise(root->left,level,curr+1,ans);
        levelwise(root->right,level,curr+1,ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int n=level(root);
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            vector<int>ans;
            levelwise(root,i,0,ans);
            res.push_back(ans);
        }
        return res;
    }
};