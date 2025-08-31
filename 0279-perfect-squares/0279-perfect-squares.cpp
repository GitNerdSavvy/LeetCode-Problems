class Solution {
public:
    vector<int> dp;
    int solve(int n) {
        if (n < 4)
            return n;
        if (dp[n] != 1e7)
            return dp[n];
        int ans = 1e7;
        for (int i = 1; i * i <= n; i++) {
            int t = i * i;
            ans = min(ans, 1 + solve(n - t));
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        dp.resize(n + 1, 1e7);
        return solve(n);
    }
};