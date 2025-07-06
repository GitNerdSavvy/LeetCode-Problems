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
    void func(TreeNode* root,int &count,int val){
            if(!root) return;
            else if(root->val>=val) {
                count++;
                val=root->val;
            }
            func(root->left,count,val);
            func(root->right,count,val);
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int count=0;
        func(root,count,root->val);
        return count;
    }
};