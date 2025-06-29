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
    int levels(TreeNode* root){
        if(root==nullptr) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void dia(TreeNode* root,int &mx){
        if(root==nullptr) return;
        int d=levels(root->left)+levels(root->right);
        mx=max(d,mx);
        dia(root->left,mx);
        dia(root->right,mx);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxD=0;
        dia(root,maxD);
        return maxD;
    }
};