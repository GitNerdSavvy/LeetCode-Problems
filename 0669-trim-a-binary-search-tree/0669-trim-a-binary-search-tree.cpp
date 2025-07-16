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
    void trim(TreeNode* root,int l,int h){
        if(!root) return;
        while(root->left){
            if(root->left->val <l){
                root->left=root->left->right;
            }else if(root->left->val > h){
                root->left=root->left->left;
            }else {
                break;
            }
        }
        while(root->right){
            if(root->right->val <l){
                root->right=root->right->right;
            }else if(root->right->val > h){
                root->right=root->right->left;
            }else {
                break;
            }
        }
        trim(root->left,l,h);
        trim(root->right,l,h);
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode *dummy=new TreeNode(INT_MAX);
        dummy->left=root;
        trim(dummy,low,high);
        return dummy->left;
    }
};