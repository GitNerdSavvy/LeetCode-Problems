class Solution {
public:
    int dp[105][105];
    int n, m;
    int func(vector<vector<int>>& nums, int i, int j) {
        if ( i >= n || j >= m)
            return 0;
        if (nums[i][j] == 1)
            return 0;
        if (i == n - 1 && j == m - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = func(nums, i + 1, j) + func(nums, i, j + 1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        // dp.clear();
         n = grid.size();
         m = grid[0].size();
        if (grid[n - 1][m - 1] == 1)
            return 0;
        memset(dp, -1, sizeof(dp));
        return func(grid, 0, 0);
    }
};