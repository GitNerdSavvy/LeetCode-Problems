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
    int levels(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
    void nth(TreeNode* root, int level, int curr, long long& sum, int& count) {
        if (!root)
            return;
        if (level == curr) {
            sum += root->val;
            count++;
            return;
        }
        nth(root->left, level, curr + 1, sum, count);
        nth(root->right, level, curr + 1, sum, count);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        int n = levels(root);
        vector<double> ans;
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            int cnt = 0;
            nth(root, i, 0, sum, cnt);
            ans.push_back(static_cast<double>(sum) / cnt);
        }
        return ans;
    }
};