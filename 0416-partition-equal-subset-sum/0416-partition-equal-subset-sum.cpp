class Solution {
public:
    int dp[205][10005];
    bool func(vector<int>& nums, int i, int k) {
        if (k == 0)
            return 1;
        if (i == nums.size())
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        if (nums[i] <= k) {
            return dp[i][k] =
                       func(nums, i + 1, k - nums[i]) || func(nums, i + 1, k);
            ;
        } else {
            return dp[i][k] = func(nums, i + 1, k);
        }
    }
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        int sm = accumulate(nums.begin(), nums.end(), 0);
        if (sm & 1)
            return false;
        return func(nums, 0, sm / 2);
    }
};