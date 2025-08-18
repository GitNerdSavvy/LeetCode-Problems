class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    char ch = grid[i][j];
                    queue<tuple<int, int, int, int>> q;
                    vis[i][j] = true;
                    q.push({i, j, -1, -1});

                    while (!q.empty()) {
                        auto [x, y, px, py] = q.front();
                        q.pop();

                        for (int d = 0; d < 4; d++) {
                            int r = x + dir[d][0];
                            int c = y + dir[d][1];
                            if (r < 0 || c < 0 || r >= n || c >= m)
                                continue;
                            if (grid[r][c] != ch)
                                continue;

                            if (vis[r][c]) {
                                if (!(r == px && c == py))
                                    return true;
                            } else {
                                vis[r][c] = true;
                                q.push({r, c, x, y});
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};