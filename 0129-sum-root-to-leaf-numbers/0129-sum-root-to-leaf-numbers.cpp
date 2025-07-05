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
    void func(TreeNode* root,int &sum,int s){
        if(!root)return;
         s = s * 10 + root->val;
        if(!root->left && !root->right){
            sum+=s;
        }
         func(root->left,sum,s );
         func(root->right,sum,s );
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        func(root,sum,0);
        return sum;
    }
};