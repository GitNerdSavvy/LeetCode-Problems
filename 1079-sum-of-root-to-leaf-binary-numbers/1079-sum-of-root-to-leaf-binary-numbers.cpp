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
    int bin(const string& binary) {
        int decimal = 0;
        int n = binary.length();
        for (int i = 0; i < n; ++i) {
            if (binary[i] == '1') {
                decimal += pow(2, n - 1 - i);
            }
        }
        return decimal;
    }
    void paths(TreeNode* root, vector<string>& v, string curr) {
        if (!root)
            return;
        curr += (char)(root->val + '0');
        if (!root->left && !root->right) {
            v.push_back(curr);
            return;
        }
        paths(root->left, v, curr);
        paths(root->right, v, curr);
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<string> v;
        paths(root, v, "");
        int sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum += bin(v[i]);
        }
        return sum;
    }
};