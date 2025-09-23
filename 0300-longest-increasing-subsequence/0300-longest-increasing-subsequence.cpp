class Solution {
public:
    int dp[2505];
    int func(vector<int>& nums, int idx) {
        if (idx < 0)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int ans = 1;
        for (int j = 0; j < idx; j++) {
            if (nums[j] < nums[idx]) {
                ans = max(ans, 1 + func(nums, j));
            }
        }
        return dp[idx] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, func(nums, i));
        }
        return ans;
    }
};