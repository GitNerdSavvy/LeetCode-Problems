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
    TreeNode* inp(TreeNode* root) {
        TreeNode* temp = root->left;
        while (temp && temp->right) {
            temp = temp->right;
        }
        return temp;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;

        if (root->val == key) {
            if (!root->left && !root->right)
                return nullptr;
            if (!root->left || !root->right) {
                if (root->left)
                    return root->left;
                return root->right;
            }
            TreeNode* pred = inp(root);
            root->val = pred->val;
            root->left = deleteNode(root->left, pred->val);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            root->left = deleteNode(root->left, key);
        }

        return root;
    }
};