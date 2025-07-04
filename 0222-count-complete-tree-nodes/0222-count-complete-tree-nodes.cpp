class Solution {
public:
    int sum=0;
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        sum++;
        countNodes(root->left);
        countNodes(root->right);
        return sum;
    }
};