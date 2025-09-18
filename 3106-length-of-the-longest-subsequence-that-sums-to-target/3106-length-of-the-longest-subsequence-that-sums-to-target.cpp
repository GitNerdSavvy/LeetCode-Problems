class Solution {
public:
    int dp[1005][1005];
    int func(vector<int>& nums, int i, int sum) {
        if (sum == 0)
            return 0;
        if (i == nums.size())
            return -1e9;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        int ans = func(nums, i + 1, sum);
        if (nums[i] <= sum) {
            ans = max(ans, 1 + func(nums, i + 1, sum - nums[i]));
        }
        return dp[i][sum] = ans;
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        memset(dp, -1, sizeof dp);
        int ans = func(nums, 0, target);
        return ans < 0 ? -1 : ans;
    }
};