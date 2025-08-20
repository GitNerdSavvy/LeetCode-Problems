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
    void dfs(TreeNode* root, unordered_map<int, int>& ump) {
        if (!root)
            return;
        ump[root->val]++;
        dfs(root->left, ump);
        dfs(root->right, ump);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> ump;
        dfs(root, ump);

        int ans = 0;
        for (auto& it : ump) {
            ans = max(ans, it.second);
        }

        vector<int> res;
        for (auto& it : ump) {
            if (it.second == ans) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};