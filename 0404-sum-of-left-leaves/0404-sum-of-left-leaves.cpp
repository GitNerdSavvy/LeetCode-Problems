class Solution {
public:
    void func(TreeNode* root,int &lsum){
        if(!root) return;
        if(root->left && !root->left->left && !root->left->right){
            lsum+=root->left->val;
        }
        func(root->left,lsum);
        func(root->right,lsum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int lsum=0;
        func(root,lsum);
        return lsum;
    }
};