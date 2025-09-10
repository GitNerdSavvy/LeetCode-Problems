class Solution {
public:
    vector<vector<int>> dp;
    int func(vector<int>& nums, int i, int k) {
        if (i == nums.size()) {
            if (k == 0)
                return 0;
            return INT_MIN;
        }
        if (dp[i][k] != -1)
            return dp[i][k];
        int nt = func(nums, i + 1, k);
        int ys = nums[i] + func(nums, i + 1, (nums[i] + k) % 3);
        return dp[i][k] = max(nt, ys);
    }
    int maxSumDivThree(vector<int>& nums) {
        dp.resize(nums.size(), vector<int>(3, -1));
        return func(nums, 0, 0);
    }
};