class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 0;
                    int cnt = 1;

                    while (!q.empty()) {
                        auto [row, col] = q.front();
                        q.pop();

                        for (int d = 0; d < 4; d++) {
                            int r = row + dir[d][0];
                            int c = col + dir[d][1];
                            if (r < 0 || c < 0 || r >= n || c >= m)
                                continue;
                            if (grid[r][c] == 0)
                                continue;
                            grid[r][c] = 0;
                            cnt++;
                            q.push({r, c});
                        }
                    }
                    ans = max(ans, cnt);
                }
            }
        }

        return ans;
    }
};