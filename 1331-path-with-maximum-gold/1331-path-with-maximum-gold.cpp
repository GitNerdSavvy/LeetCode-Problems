class Solution {
public:
    int n, m;
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int func(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0)
            return 0;
        int temp = grid[i][j];
        grid[i][j] = 0;
        int curr = temp;
        for (int d = 0; d < 4; d++) {
            curr = max(curr, temp + func(grid, i + dir[d][0], j + dir[d][1]));
        }
        grid[i][j] = temp;
        return curr;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for (int i = 0; i<n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    ans = max(ans, func(grid, i, j));
                }
            }
        }
        return ans;
    }
};