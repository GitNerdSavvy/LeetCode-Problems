class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> bfs(vector<vector<int>>& heights, int n, int m,
                             queue<pair<int, int>>& q) {
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            visited[r][c] = true;
            for (int d = 0; d < 4; d++) {
                int row = r + dir[d][0];
                int col = c + dir[d][1];
                if (row >= 0 && col >= 0 && row < n && col < m &&
                    !visited[row][col] && heights[row][col] >= heights[r][c]) {
                    q.push({row, col});
                }
            }
        }
        return visited;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        queue<pair<int, int>> p;
        queue<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            p.push({i, 0});
            a.push({i, m - 1});
        }
        for (int j = 0; j < m; j++) {
            p.push({0, j});
            a.push({n - 1, j});
        }
        vector<vector<bool>> pa = bfs(heights, n, m, p);
        vector<vector<bool>> aa = bfs(heights, n, m, a);
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pa[i][j] && aa[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};