class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 0;
                }
            }
        }
        int ans = 0;
            int dx[4] = {1, -1, 0, 0};
            int dy[4] = {0, 0, 1, -1};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (grid[x][y] == 0) {
                ans = max(ans, vis[x][y]);
            }
            for (int d = 0; d < 4; d++) {
                int r = x + dx[d];
                int c = y + dy[d];

                if (r >= 0 && r < n && c >= 0 && c < m && vis[r][c] == -1) {
                    vis[r][c] = vis[x][y] + 1;
                    q.push({r, c});
                }
            }
        }
        return ans == 0 ? -1 : ans;
    }
};