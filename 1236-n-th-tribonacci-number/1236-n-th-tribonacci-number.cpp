class Solution {
public:
    vector<int> dp;
    // int dfs(int n) {
    //     if (n == 0)
    //         return 0;
    //     if (n == 1 || n == 2)
    //         return 1;
    //     if (dp[n] != -1)
    //         return dp[n];
    //     return dp[n] = dfs(n - 1) + dfs(n - 2) + dfs(n - 3);
    // }
    int tribonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        dp.assign(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1, dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};