class Solution {
public:
    const int MOD=1e9+7;
    int dp[1005][1005];
    long long func(int n, int k) {
        if (n == 1 && k == 1)
            return 1;
        if (k == 0 || k > n)
            return 0;
        if (dp[n][k] != -1)
            return dp[n][k];
        long long a = func(n - 1, k - 1);
        long long b = (long long)(n - 1) * func(n - 1, k) % MOD;
        return dp[n][k] = (a + b) % MOD;
    }
    int rearrangeSticks(int n, int k) {
        memset(dp,-1,sizeof dp);
        return func(n,k);
    }
};