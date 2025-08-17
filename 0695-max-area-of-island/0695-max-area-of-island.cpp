class Solution {
public:
    int row, col;

    void dfs(vector<vector<int>>& grid, int r, int c, int& cnt) {
        if (r < 0 || c < 0 || r >= row || c >= col || grid[r][c] == 0)
            return;
        grid[r][c] = 0;
        cnt++;
        dfs(grid, r + 1, c, cnt);
        dfs(grid, r - 1, c, cnt);
        dfs(grid, r, c + 1, cnt);
        dfs(grid, r, c - 1, cnt);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    int cnt = 0;
                    dfs(grid, i, j, cnt);
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};