class Solution {
public:
    int levels(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        int a = levels(root->left);
        int b = levels(root->right);
        if (abs(a - b) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};