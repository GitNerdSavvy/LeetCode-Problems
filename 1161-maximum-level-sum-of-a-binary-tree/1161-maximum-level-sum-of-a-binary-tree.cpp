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
    int maxLevelSum(TreeNode* root) {
        if (!root)
            return -1;
        queue<TreeNode*> q;
        int mx = root->val;
        int mxLevel = 1, curr = 1;
        q.push(root);
        while (!q.empty()) {
            int currSum = 0;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                currSum += node->val;
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (currSum > mx) {
                mx = currSum;
                mxLevel = curr;
            }
            curr++;
        }
        return mxLevel;
    }
};