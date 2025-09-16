class Solution {
public:
    int n, m;
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void solve(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        for (int d = 0; d < 4; d++) {
            solve(grid, i + dir[d][0], j + dir[d][1]);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) &&
                    grid[i][j] == 1) {
                    solve(grid, i, j);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};