class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n, m;
    int dp[205][205];
    int func(vector<vector<int>>& matrix, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 1;
        for (int d = 0; d < 4; d++) {
            int r = i + dir[d][0];
            int c = j + dir[d][1];
            if (r >= 0 && c >= 0 && r < n && c < m &&
                matrix[r][c] > matrix[i][j]) {
                ans = max(ans, 1 + func(matrix, r, c));
            }
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        memset(dp, -1, sizeof dp);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, func(matrix, i, j));
            }
        }
        return ans;
    }
};