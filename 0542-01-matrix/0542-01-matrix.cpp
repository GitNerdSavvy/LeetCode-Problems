class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> matrix(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    matrix[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int r = row + dir[d][0];
                int c = col + dir[d][1];
                if (r >= 0 && c >= 0 && r < n && c < m && matrix[r][c] == -1) {
                    matrix[r][c] = matrix[row][col] + 1;
                    q.push({r, c});
                }
            }
        }

        return matrix;
    }
};