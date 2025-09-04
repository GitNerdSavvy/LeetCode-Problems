class Solution {
public:
    int dp[100005];

    int func(vector<int>& nums, int i) {
        if (i == nums.size() - 1)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int t = min((int)nums.size() - 1, i + nums[i]);
        int ans = 10005;
        for (int j = i + 1; j <= t; j++) {
            ans = min(ans, 1 + func(nums, j));
        }
        return dp[i] = ans;
    }

    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return func(nums, 0);
    }
};