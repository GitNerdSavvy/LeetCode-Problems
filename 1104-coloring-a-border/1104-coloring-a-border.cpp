class Solution {
public:
    vector<pair<int, int>> res;
    void dfs(vector<vector<int>>& grid, int r, int c, int color, int cl) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() ||
            grid[r][c] != cl)
            return;
        grid[r][c] = -color;
        dfs(grid, r + 1, c, color, cl), dfs(grid, r - 1, c, color, cl),
            dfs(grid, r, c + 1, color, cl), dfs(grid, r, c - 1, color, cl);
        if (!(r == 0 || c == 0 || r == grid.size() - 1 ||
              c == grid[0].size() - 1 || grid[r + 1][c] != -color ||
              grid[r - 1][c] != -color || grid[r][c + 1] != -color ||
              grid[r][c - 1] != -color)) {
            res.push_back({r, c});
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col,
                                    int color) {
        int cl = grid[row][col];
        if (cl == color)
            return grid;
        dfs(grid, row, col, color, cl);
        for (auto it : res) {
            int i = it.first;
            int j = it.second;
            grid[i][j] = cl;
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] < 0) {
                    grid[i][j] *= -1;
                }
            }
        }
        return grid;
    }
};