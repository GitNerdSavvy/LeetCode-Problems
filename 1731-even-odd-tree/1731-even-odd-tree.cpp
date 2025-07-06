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
    bool isEvenOddTree(TreeNode* root) {
        if (!root)
            return true;

        queue<TreeNode*> q;
        q.push(root);
        bool evenLevel = true;

        while (!q.empty()) {
            int size = q.size();
            int prev = evenLevel ? INT_MIN : INT_MAX;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                int val = node->val;

                if (evenLevel) {
                    if (val % 2 == 0 || val <= prev)
                        return false;
                } else {
                    if (val % 2 == 1 || val >= prev)
                        return false;
                }
                prev = val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            evenLevel = !evenLevel;
        }

        return true;
    }
};