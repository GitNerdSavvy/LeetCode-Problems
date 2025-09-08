class Solution {
public:
    int dp[1005][4005];
    int offset = 2000;

    int func(vector<int>& nums, int t, int i) {
        if (i == nums.size()) {
            return (t == 0) ? 1 : 0;
        }
        if (dp[i][t + offset] != -1)
            return dp[i][t + offset];
        return dp[i][t + offset] = func(nums, t - nums[i], i + 1) +
                                   func(nums, t + nums[i], i + 1);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof dp);
        return func(nums, target, 0);
    }
};