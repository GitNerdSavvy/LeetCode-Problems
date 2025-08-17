class Solution {
public:
    vector<vector<int>> dir = {{2, 1},   {1, 2},   {-1, 2}, {-2, 1},
                               {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        if (grid[0][0] != 0)
            return false;
        q.push({0, 0});
        int cnt = 0;
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            if (grid[row][col] != cnt)
                return false;
            if (cnt == n * m - 1)
                return true;
            for (auto& d : dir) {
                int r = row + d[0];
                int c = col + d[1];
                if (r >= 0 && c >= 0 && r < n && c < m &&
                    grid[r][c] == cnt + 1) {
                    q.push({r, c});
                    break;
                }
            }
            cnt++;
        }
        return false;
    }
};