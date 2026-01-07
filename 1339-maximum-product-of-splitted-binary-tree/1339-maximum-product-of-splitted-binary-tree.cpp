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
#define ll long long
    static const int modi = 1e9 + 7;
    ll total = 0;
    ll ans = 0;
    ll sum(TreeNode* root) {
        if (!root)
            return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
    ll dfs(TreeNode* root) {
        if (!root)
            return 0;

        ll left = dfs(root->left);
        ll right = dfs(root->right);

        ll subSum = root->val + left + right;

        ans = max(ans, subSum * (total - subSum));

        return subSum;
    }
    int maxProduct(TreeNode* root) {
        total = sum(root);
        dfs(root);
         return ans % modi;
    }
};