class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m)
            return 1;
        if (grid[i][j] == 0)
            return 1;
        if (grid[i][j] == -1)
            return 0;
        int cnt = 0;
        grid[i][j] = -1;
        for (int d = 0; d < 4; d++) {
            int row = i + dir[d][0];
            int col = j + dir[d][1];
            cnt += dfs(grid, row, col);
        }
        return cnt;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return dfs(grid, i, j);
                }
            }
        }
        return 0;
    }
};