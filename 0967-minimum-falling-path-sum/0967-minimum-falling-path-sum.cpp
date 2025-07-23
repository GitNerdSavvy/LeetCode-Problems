class Solution {
public:
    vector<vector<int>> dp;
    // int func(vector<vector<int>>& matrix, int n, int m) {
    //     if (m < 0 || m >= matrix[0].size())
    //         return 1e8;
    //     if (n == 0)
    //         return matrix[0][m];
    //     if(dp[n][m] !=-1) return dp[n][m];

    //     int l = matrix[n][m] + func(matrix, n - 1, m - 1);
    //     int s = matrix[n][m] + func(matrix, n - 1, m);
    //     int r = matrix[n][m] + func(matrix, n - 1, m + 1);

    //     return min({l, s, r});
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // int m = n;
        dp.assign(n, vector<int>(n, 0));
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int l = j > 0 ? dp[i - 1][j - 1] : 1e8;
                int u = dp[i - 1][j];
                int r = j < n - 1 ? dp[i - 1][j + 1] : 1e8;
                dp[i][j] = matrix[i][j] + min({l, u, r});
            }
        }
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[n - 1][j]);
        }
        return ans;
    }
};