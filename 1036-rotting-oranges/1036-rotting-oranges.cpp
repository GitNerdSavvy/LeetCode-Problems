class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    cnt++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
            int minutes = 0;
            q.push({-1, -1});
            while (!q.empty()) {
                auto it = q.front();
                q.pop();
                int r = it.first;
                int c = it.second;
                if (r == -1 && c == -1) {
                    minutes++;
                    if (!q.empty()) {
                        q.push({-1, -1});
                    } else {
                        break;
                    }
                } else {
                    for (int d = 0; d < 4; d++) {
                        int row = r + dir[d][0];
                        int col = c + dir[d][1];
                        if (row < 0 || col < 0 || row >= n || col >= m)
                            continue;
                        if (grid[row][col] == 2 || grid[row][col] == 0)
                            continue;
                       cnt--;
                        grid[row][col] = 2;
                        q.push({row, col});
                    }
                }
            }
        
        return (cnt == 0) ? minutes-1 : -1;
    }
};