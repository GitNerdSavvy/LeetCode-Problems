class Solution {
public:
    void depth(TreeNode* root, int& ans, int t) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            ans = min(ans, t);
        }
        depth(root->left, ans, t + 1);
        depth(root->right, ans, t + 1);
    }
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        int ans = INT_MAX;
        depth(root, ans, 1);
        return ans;
    }
};