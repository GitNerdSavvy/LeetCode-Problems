class Solution {
public:
    int solve(vector<int>& v, int n, int i, vector<int>& dp) {
     if (i >= n) return 0;
     if (dp[i] != -1) return dp[i];
     int eve = v[i] + solve(v, n, i + 2, dp);
     int odd = solve(v, n, i + 1, dp);
     dp[i] = max(eve, odd);
     return dp[i];
  }

   int rob(vector<int>& nums) {
     int n = nums.size();
     vector<int> dp(n, -1);
     return solve(nums, n, 0, dp);
  }
};