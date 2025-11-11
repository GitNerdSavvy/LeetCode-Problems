class Solution {
public:
    int x;
    int dp[605][105][105];
    int cnt(string s, char k) {
        int t = 0;
        for (auto it : s) {
            if (it == k) {
                t++;
            }
        }
        return t;
    }
    int func(vector<string>& nums, int i, int m, int n) {
        if (i == x)
            return 0;

        if (dp[i][m][n] != -1)
            return dp[i][m][n];
        int ans = func(nums, i + 1, m, n);
        int res = -1e8;
        int zeros = cnt(nums[i], '0');
        int ones = cnt(nums[i], '1');
        if (m >= zeros && n >= ones)
            ans = max(ans, 1 + func(nums, i + 1, m - zeros, n - ones));

        ans = max(ans, res);
        return dp[i][m][n] = ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        x = strs.size();
        memset(dp, -1, sizeof dp);
        return func(strs, 0, m, n);
    }
};