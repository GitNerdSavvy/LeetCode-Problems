class Solution {
public:
    double dp[30][30][105];
    vector<vector<int>> dir = {{2, 1},   {1, 2},   {-1, 2}, {1, -2},
                               {-1, -2}, {-2, -1}, {-2, 1}, {2, -1}};
    double func(int n, int i, int j, int k) {
        if (i < 0 or j < 0 or i >= n or j >= n)
            return 0;
        if (k == 0)
            return 1;
        if (dp[i][j][k] > -0.9)
            return dp[i][j][k];
        double ans = 0.0;
        for (int d = 0; d < 8; d++) {

            ans += func(n, i + dir[d][0], j + dir[d][1], k - 1) * (0.125);
        }
        return dp[i][j][k] = ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        memset(dp, -1, sizeof dp);
        if (k == 0)
            return 1;
        double ans = func(n, row, column, k);
        return ans;
    }
};