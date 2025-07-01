class Solution {
public:
    void secMin(TreeNode* root, int& mn, long long &mn2) {
        if (!root)
            return;
        if (root->val > mn && root->val < mn2) {
            mn2 = root->val;
        } else if (root->val == mn) {
            secMin(root->left, mn, mn2);
            secMin(root->right, mn, mn2);
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        int mn = root->val;
       long long mn2 = LLONG_MAX;
        if (!root)
            return -1;
        secMin(root, mn, mn2);
        return mn2 == LLONG_MAX ? -1 : (int)mn2;
    }
};