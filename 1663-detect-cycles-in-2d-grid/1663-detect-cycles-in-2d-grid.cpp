class Solution {
public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;
    vector<vector<bool>> vis;
    bool dfs(vector<vector<char>>& grid, int i, int j, int px, int py,
             char ch) {
        vis[i][j] = true;
        for (auto [dx, dy] : dir) {
            int nx = i + dx, ny = j + dy;
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (grid[nx][ny] != ch)
                continue;
            if (nx == px && ny == py)
                continue;
            if (vis[nx][ny])
                return true;
            if (dfs(grid, nx, ny, i, j, ch))
                return true;
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.assign(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (dfs(grid, i, j, -1, -1, grid[i][j])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};