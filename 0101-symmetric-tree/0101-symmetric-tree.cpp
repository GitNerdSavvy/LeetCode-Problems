/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool same(TreeNode *left, TreeNode* right){
    if(!left && !right) return true;
            if(!left || !right) return false;

            if(left->val == right->val){
                return same(left->left,right->right) && same(left->right,right->left);
            }
            return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return same(root->left,root->right);
    }
};