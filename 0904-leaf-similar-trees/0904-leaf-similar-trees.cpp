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
    void simi(TreeNode* root, string& str) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            str += root->val;
        }
        simi(root->left, str);
        simi(root->right, str);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1, s2;
        simi(root1, s1);
        simi(root2, s2);
        if (s1.length() != s2.length())
            return false;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i])
                return false;
        }
        return true;
    }
};