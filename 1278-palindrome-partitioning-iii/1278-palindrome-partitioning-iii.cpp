class Solution {
public:
    int dp[105][105];
    int memo[105][105];
    int cost(int i, int j, string& s) {
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = (s[i] != s[j]) + cost(i + 1, j - 1, s);
    }

    int rec(int n, int k, string& s) {
        if (n < 0 && k == 0)
            return 0;
        if (n < 0 || k == 0)
            return 1e9;

        if (memo[n][k] != -1)
            return memo[n][k];

        int ans = 1e9;

        for (int i = n; i >= 0; i--) {
            ans = min(ans, rec(i - 1, k - 1, s) + cost(i, n, s));
        }

        return memo[n][k] = ans;
    }

    int palindromePartition(string s, int k) {
        memset(dp, -1, sizeof dp);
        memset(memo, -1, sizeof memo);
        return rec(s.length() - 1, k, s);
    }
};