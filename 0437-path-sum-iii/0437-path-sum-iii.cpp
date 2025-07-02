/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void paths(TreeNode* root, long long sum, int& ans) {
        if (!root)
            return;
        if (root->val ==(long long) sum) {
            ans++;
        }
        paths(root->left, sum -(long long) (root->val), ans);
        paths(root->right, sum -(long long) (root->val), ans);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        int ans = 0;
        paths(root,(long long) targetSum, ans);
        ans += (pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum));
        return ans;
    }
};