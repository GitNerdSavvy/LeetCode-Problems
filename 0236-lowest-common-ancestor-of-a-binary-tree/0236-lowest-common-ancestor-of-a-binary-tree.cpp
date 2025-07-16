/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool exist(TreeNode* root,TreeNode* ptr){
        if(!root) return false;
        if(root==ptr) return true;
        return exist(root->left,ptr) || exist(root->right,ptr);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(exist(root->left,p) && exist(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        else if(exist(root->right,p) && exist(root->right,q)) return lowestCommonAncestor(root->right,p,q);
        else return root;
    }
};