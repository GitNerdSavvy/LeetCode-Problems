class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;
    // int dfs(vector<vector<int>>& grid, int i, int j) {
    //     if (i < 0 || j < 0 || i >= n || j >= m)
    //         return 1;
    //     if (grid[i][j] == 0)
    //         return 1;
    //     if (grid[i][j] == -1)
    //         return 0;
    //     int cnt = 0;
    //     grid[i][j] = -1;
    //     for (int d = 0; d < 4; d++) {
    //         int row = i + dir[d][0];
    //         int col = j + dir[d][1];
    //         cnt += dfs(grid, row, col);
    //     }
    //     return cnt;
    // }
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j]=-1;
                    break;
                }
            }
        }
        int cnt = 0;
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int r = row + dir[d][0];
                int c = col + dir[d][1];
                if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 0) {
                    cnt++;
                    continue;
                }
                if (grid[r][c] == 1) {
                    q.push({r, c});
                }
                grid[r][c] = -1;
            }
        }
        return cnt;
    }
};