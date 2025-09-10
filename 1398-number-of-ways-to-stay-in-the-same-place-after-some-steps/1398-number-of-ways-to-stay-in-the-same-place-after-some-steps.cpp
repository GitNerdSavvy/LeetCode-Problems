class Solution {
public:
#define MOD 1000000007
    int dp[505][505];
    int func(int i, int j, int steps, int len) {
        if (j < 0 || j >= len)
            return 0;
        if (i == steps)
            return (j == 0);

        if (dp[i][j] != -1)
            return dp[i][j];

        long long ans = 0;
        ans = (ans + func(i + 1, j + 1, steps, len)) % MOD;
        ans = (ans + func(i + 1, j - 1, steps, len)) % MOD;
        ans = (ans + func(i + 1, j, steps, len)) % MOD;

        return dp[i][j] = ans;
    }
    int numWays(int steps, int arrLen) {
        memset(dp, -1, sizeof dp);
        return func(0, 0, steps, arrLen);
    }
};