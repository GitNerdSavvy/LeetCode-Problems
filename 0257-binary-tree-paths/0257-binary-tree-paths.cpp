class Solution {
public:
    void allPaths(TreeNode* root, vector<string> &ans, string s) {
        if (!root)
            return;

        if (!s.empty()) {
            s += "->";
        }
        s += to_string(root->val);

        if (!root->left && !root->right) {
            ans.push_back(s);
            return;
        }
        allPaths(root->left, ans, s);
        allPaths(root->right, ans, s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        allPaths(root, ans, "");

        return ans;
    }
};