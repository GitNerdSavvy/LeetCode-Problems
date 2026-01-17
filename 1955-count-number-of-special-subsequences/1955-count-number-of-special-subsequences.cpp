class Solution {
public:
    const int mod = 1000000007;
    int dp[100005][4];

    int func(vector<int>& nums, int idx, int stage) {
        if (idx == nums.size())
            return stage == 2;

        if (dp[idx][stage + 1] != -1)
            return dp[idx][stage + 1];

        long long ans = func(nums, idx + 1, stage);

        if (stage == -1 && nums[idx] == 0)
            ans = (ans + func(nums, idx + 1, 0)) % mod;

        if (stage == 0 && nums[idx] == 0)
            ans = (ans + func(nums, idx + 1, 0)) % mod;

        if (stage == 0 && nums[idx] == 1)
            ans = (ans + func(nums, idx + 1, 1)) % mod;

        if (stage == 1 && nums[idx] == 1)
            ans = (ans + func(nums, idx + 1, 1)) % mod;

        if (stage == 1 && nums[idx] == 2)
            ans = (ans + func(nums, idx + 1, 2)) % mod;

        if (stage == 2 && nums[idx] == 2)
            ans = (ans + func(nums, idx + 1, 2)) % mod;

        return dp[idx][stage + 1] = ans;
    }

    int countSpecialSubsequences(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return func(nums, 0, -1);
    }
};
